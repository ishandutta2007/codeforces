#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<unordered_map>
#include<bitset>
#include<cctype>
using namespace std;
int n,m;
string name,buf;
unordered_map<string,int> mp;
int op[5010];//OR:1,AND:2,XOR:3
int var1[5010],var2[5010];
bitset<1010> bits[5010];
int flag[5010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	mp[string("?")]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>name>>buf>>buf;
		mp[name]=i;
		if(isdigit(buf[0]))
		{
			for(int t=0;t<buf.length();++t)bits[i][t]=buf[t]-'0';
			continue;
		}
		var1[i]=mp[buf];
		cin>>buf;
		if(buf=="OR")op[i]=1;
		else if(buf=="AND")op[i]=2;
		else op[i]=3;
		cin>>buf;
		var2[i]=mp[buf];
	}
	string minval,maxval;
	for(int i=0;i<m;i++)
	{
		int cnt0=0,cnt1=0;
		memset(flag,0,sizeof(flag));
		for(int j=1;j<=n;j++)
		{
			if(op[j]==1)
			{
				flag[j]=flag[var1[j]]|flag[var2[j]];
			}
			else if(op[j]==2)
			{
				flag[j]=flag[var1[j]]&flag[var2[j]];
			}
			else if(op[j]==3)
			{
				flag[j]=flag[var1[j]]^flag[var2[j]];
			}
			else
			{
				flag[j]=bits[j][i];
			}
			if(flag[j])cnt0++;
		}
		memset(flag,0,sizeof(flag));
		flag[0]=1;
		for(int j=1;j<=n;j++)
		{
			if(op[j]==1)
			{
				flag[j]=flag[var1[j]]|flag[var2[j]];
			}
			else if(op[j]==2)
			{
				flag[j]=flag[var1[j]]&flag[var2[j]];
			}
			else if(op[j]==3)
			{
				flag[j]=flag[var1[j]]^flag[var2[j]];
			}
			else
			{
				flag[j]=bits[j][i];
			}
			if(flag[j])cnt1++;
		}
		if(cnt1>cnt0)
		{
			maxval+='1';
			minval+='0';
		}
		else if(cnt1<cnt0)
		{
			maxval+='0';
			minval+='1';
		}
		else
		{
			maxval+='0';
			minval+='0';
		}
	}
	cout<<minval<<endl<<maxval<<endl;
	return 0;
}