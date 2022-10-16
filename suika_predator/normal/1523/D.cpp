#include<bits/stdc++.h>
using namespace std;
char s[233333][77];
int cnt[33333];
mt19937 ran;
char ans[77];
int maxx;
int main()
{
	ios_base::sync_with_stdio(false);
	ran.seed((unsigned long long)(new char));
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	memset(ans,'0',sizeof(ans));
	for(int tt=1;tt<=100;tt++)
	{
		int r=ran()%n+1;
//		cerr<<"rand "<<r<<endl;
		vector<int> sp;
		for(int b=0;b<m;b++)
			if(s[r][b]=='1')
				sp.push_back(b);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			int val=0;
			for(int j=0;j<(int)sp.size();j++)
			{
				if(s[i][sp[j]]=='1')
					val|=(1<<j);
			}
			cnt[val]++;
		}
		for(int i=1;i<(1<<sp.size());i<<=1)
		{
			for(int j=0;j<(1<<sp.size());j+=i<<1)
			{
				for(int k=j;k<i+j;k++)
				{
					cnt[k]+=cnt[k+i];
				}
			}
		}
//		cerr<<"fwt end"<<endl;
//		for(int i=0;i<(1<<sp.size());i++)
//			cerr<<i<<' '<<cnt[i]<<endl;
		for(int i=0;i<(1<<sp.size());i++)
		{
			if(__builtin_popcount(i)>maxx&&cnt[i]>=(n+1)/2)
			{
				maxx=__builtin_popcount(i);
				memset(ans,'0',sizeof(ans));
				for(int j=0;j<(int)sp.size();j++)
				{
					if((i>>j)&1)
						ans[sp[j]]++;
				}
			}
		}
	}
	ans[m]=0;
	cout<<ans<<endl;
	return 0;
}