#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<unordered_map>
using namespace std;
int n,m,r,k;
double ans;
struct pp
{
	int x,y;
	long long cnt;
	inline pp(int a,int b,long long c){x=a,y=b,cnt=c;}
	inline bool operator<(const pp &p)const{return 1ll*x*y<1ll*p.x*p.y;}
};
priority_queue<pp> pq;
unordered_map<int,unordered_map<int,bool> > vis;
int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&k);
	if(n>m)swap(n,m);
	int xl=min(r,n-r+1),yl=min(r,m-r+1);
	vis[xl][yl]=1;
	//cout<<xl<<' '<<yl<<endl;
	pq.push(pp(xl,yl,1ll*(n-xl*2+2)*(m-yl*2+2)));
	int x=0,y=0;
	while(!pq.empty())
	{
		pp tmp=pq.top();pq.pop();
		x=tmp.x,y=tmp.y;
		if(tmp.cnt>=k)
		{
			//cout<<1ll*x*y<<' '<<tmp.cnt<<endl;
			ans+=1.0*k*x*y;
			break;
		}
		else
		{
			//cout<<1ll*x*y<<' '<<tmp.cnt<<endl;
			ans+=1.0*tmp.cnt*x*y;
			if(y==yl)
			{
				if(!vis[x-1][y])
					pq.push(pp(x-1,y,2*(m-yl*2+2))),vis[x-1][y]=1;
			}
			else
			{
				if(!vis[x-1][y])
					pq.push(pp(x-1,y,4)),vis[x-1][y]=1;
			}
			if(x==xl)
			{
				if(!vis[x][y-1])
					pq.push(pp(x,y-1,2*(n-xl*2+2))),vis[x][y-1]=1;
			}
			else
			{
				if(!vis[x][y-1])
					pq.push(pp(x,y-1,4)),vis[x][y-1]=1;
			}
			k-=tmp.cnt;
		}
	}
	//cout<<ans<<endl;
	
	printf("%.12lf\n",ans/(n-r+1)/(m-r+1));
	return 0;
}