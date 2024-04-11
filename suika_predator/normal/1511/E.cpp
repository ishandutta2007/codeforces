#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long pow2[333333];
int cnt=0;
long long ans=0;
void gao(long long len)
{
	ans+=(len/2)*pow2[cnt-len]%MOD;
//	cerr<<(len/2)*pow2[cnt-len]<<endl;
	for(long long i=2;i<len;i++)
	{
		ans+=2*(i/2)*pow2[cnt-i-1]%MOD;
		ans+=(len-i-1)*(i/2)%MOD*pow2[cnt-i-2]%MOD;
//		cerr<<2*(i/2)*pow2[cnt-i-1]+(len-i-1)*(i/2)%MOD*pow2[cnt-i-2]<<endl;
	}
}
string s[333333];
int main()
{
	ios_base::sync_with_stdio(false);
	pow2[0]=1;
	for(int i=1;i<=300000;i++)
		pow2[i]=pow2[i-1]*2%MOD;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>(s[i]);
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='o')
				cnt++;
		}
	}
	for(int i=0;i<n;i++)
	{
		int cur=0;
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='o')
				cur++;
			else if(cur)
			{
				gao(cur);
				cur=0;
			}
		}
		if(cur)
			gao(cur);
	}
	for(int i=0;i<m;i++)
	{
		int cur=0;
		for(int j=0;j<n;j++)
		{
			if(s[j][i]=='o')
				cur++;
			else if(cur)
			{
				gao(cur);
				cur=0;
			}
		}
		if(cur)
			gao(cur);
	}
	cout<<ans%MOD<<endl;
	return 0;
}