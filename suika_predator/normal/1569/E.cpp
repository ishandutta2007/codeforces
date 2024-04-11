#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int pw[233];
map<int,vector<int> > mp[2],mp2[2];
int D;
void cal(const vector<int> &tmp,int type)
{
//	cerr<<"cal "<<D<<' '<<type<<": ";
//	for(auto z:tmp)cerr<<z<<' ';
	long long val=0;
	for(int i=0;i<(int)tmp.size();i++)
	{
		val+=1ll*(D+i)*(pw[tmp[i]]);
	}
	val%=MOD;
//	cerr<<"= "<<val<<endl;
	if(D==1)mp[type][val]=tmp;
	else mp2[type][val]=tmp;
}
void solve(const vector<int> &ans,const vector<int> &tmp,int k)
{
//	cerr<<"solve "<<k<<": ";
//	for(auto z:tmp)cerr<<z<<' ';
//	cerr<<endl;
	if(k==0)
	{
		vector<int> tans=ans;
		tans[tmp[0]]=1;
		cal(tans,0);
		tans[tmp[0]]=2;
		cal(tans,1);
		return;
	}
	for(int i=0;i<(1<<(1<<(k-1)));i++)
	{
		vector<int> tans=ans;
		vector<int> newpos;
		for(int j=0;j<(1<<(k-1));j++)
		{
			if((i>>j)&1)
			{
				tans[tmp[j*2]]=(1<<k)+1;
				newpos.push_back(tmp[j*2+1]);
			}
			else
			{
				tans[tmp[j*2+1]]=(1<<k)+1;
				newpos.push_back(tmp[j*2]);
			}
		}
		solve(tans,newpos,k-1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int k,A,h;
	cin>>k>>A>>h;
	pw[0]=1;
	for(int i=1;i<=50;i++)pw[i]=1ll*pw[i-1]*A%MOD;
	vector<int> pos,ans(1<<(k-1));
	for(int i=0;i<(1<<(k-1));i++)pos.push_back(i);
	D=1;
	solve(ans,pos,k-1);
	pos.clear();
	for(int i=0;i<(1<<(k-1));i++)pos.push_back(i);
	D=(1<<(k-1))+1;
	solve(ans,pos,k-1);
	for(auto &x:mp[0])
	{
//		cerr<<"check 0 "<<x.first<<' '<<(h-x.first+MOD)%MOD<<endl;
		if(mp2[1].find((h-x.first+MOD)%MOD)!=mp2[1].end())
		{
			for(auto z:x.second)
			{
				cout<<z<<' ';
			}
			auto tmp=mp2[1][(h-x.first+MOD)%MOD];
			for(auto z:tmp)
			{
				cout<<z<<' ';
			}
			return 0;
		}
	}
	for(auto &x:mp[1])
	{
//		cerr<<"check 1 "<<x.first<<' '<<(h-x.first+MOD)%MOD<<endl;
		if(mp2[0].find((h-x.first+MOD)%MOD)!=mp2[0].end())
		{
			for(auto z:x.second)
			{
				cout<<z<<' ';
			}
			auto tmp=mp2[0][(h-x.first+MOD)%MOD];
			for(auto z:tmp)
			{
				cout<<z<<' ';
			}
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}