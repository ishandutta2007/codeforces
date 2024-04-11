#include<bits/stdc++.h>//1
#define int long long
using namespace std;
const int mod=998244353;
int l,r,K,num[20][2][2][2000],sum[20][2][2][2000];
int solve(string s)
{
	memset(num,0,sizeof(num));
	memset(sum,0,sizeof(sum));
	num[0][0][0][0]=1;
	for(int i=0;i<s.size();i++)
		for(int j=0;j<2;j++)
			for(int l=0;l<2;l++)
				for(int k=0;k<(1<<10);k++)
					if(num[i][j][l][k])
					{
						int nn=num[i][j][l][k];
						int ss=sum[i][j][l][k];
						int lim=(j?9:s[i]-'0');
						for(int t=0;t<=lim;t++)
						{
							int c=k;
							if(l||t)
								c|=(1<<t);
							(num[i+1][j||(t<lim)][l||t][c]+=nn)%=mod;
							(sum[i+1][j||(t<lim)][l||t][c]+=ss*10%mod+t*nn%mod)%=mod;
						}
					}
	int ans=0;
		for(int j=0;j<2;j++)
			for(int l=0;l<2;l++)
				for(int k=0;k<(1<<10);k++)
					if(__builtin_popcount(k)<=K)
						(ans+=sum[s.size()][j][l][k])%=mod;
	return ans;
}
signed main()
{
	scanf("%lld %lld %lld",&l,&r,&K);
	cout<<(solve(to_string(r))+mod-solve(to_string(l-1)))%mod;
	return 0; 
}