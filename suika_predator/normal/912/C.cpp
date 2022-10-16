#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
int n,m;
int bon,inc,dam;
set<long long> s;
map<long long,int> delta;
struct update
{
	int t,h;
	inline update(const int xx,const int yy){t=xx,h=yy;}
	inline bool operator<(const update &u)const{return t<u.t;}
};
struct enemy
{
	int mh,reg;
	long long curh,t;
	vector<update> upd;
}e[233333];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&bon,&inc,&dam);
	int id,xx,yy;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&e[i].mh,&xx,&e[i].reg);
		e[i].upd.push_back(update(0,xx));
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&xx,&id,&yy);
		e[id].upd.push_back(update(xx,yy));
	}
	for(int i=1;i<=n;i++)
	{
		sort(e[i].upd.begin(),e[i].upd.end());
		s.clear();
		for(int j=0;j<e[i].upd.size();j++)
		{
			update &upd=e[i].upd[j];
			s.insert(upd.t-1);
			s.insert(upd.t);
			if(e[i].mh<=dam||e[i].reg==0||upd.h>dam)continue;
			long long t=upd.t+(dam-upd.h)/e[i].reg;
			if(j==e[i].upd.size()-1||t<e[i].upd[j+1].t)
			{
				s.insert(t);
				s.insert(t+1);
			}
		}
		int cur=0,status=0;
		for(auto time:s)
		{
			//cout<<i<<' '<<"time = "<<time<<endl;
			if(time<0)continue;
			while(cur<e[i].upd.size()&&time>=e[i].upd[cur].t)
			{
				e[i].curh=e[i].upd[cur].h;
				e[i].t=e[i].upd[cur].t;
				if(e[i].curh<=dam&&status==0)
				{
					delta[time]++;
					status=1;
					//cout<<"delta+1"<<endl;
				}
				else if(e[i].curh>dam&&status==1)
				{
					delta[time]--;
					status=0;
					//cout<<"delta-1"<<endl;
				}
				cur++;
			}
			if(min(e[i].curh+(time-e[i].t)*e[i].reg,0ll+e[i].mh)>dam&&status==1)
			{
				delta[time]--;
				status=0;
				//cout<<"delta-1"<<endl;
			}
		}
		if(status==1&&inc)
		{
			printf("-1\n");
			return 0;
		}
	}
	int cnt=0;
	for(auto __:delta)
	{
		int t=__.first,d=__.second;
		ans=max(ans,(bon+1ll*inc*(t-1))*cnt);
		cnt+=d;
		//cout<<t<<' '<<d<<' '<<cnt<<' '<<(bon+1ll*inc*t)*cnt<<endl;
		ans=max(ans,(bon+1ll*inc*t)*cnt);
	}
	printf("%lld\n",ans);
	return 0;
}