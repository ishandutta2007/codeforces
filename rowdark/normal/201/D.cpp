#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string p[20],s[500011];
int dp[40000][110];
int nxt[500001][16],n,m,k,ans,la;
int g[17],cc[32770];
void updata(int &x,int y){if(y<x) x=y;}
int main(){
	for(int i=14;i>-1;--i) g[i]=g[i+1]|(1<<i);
	for(int i=1;i<32768;++i) cc[i]=cc[i^(i&-i)]+1;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i) cin>>p[i];
	ans=n*(n-1)/2+1;
	cin>>m;
	for(int mm=1;mm<=m;++mm)
	{
		cin>>k;
		for(int i=0;i<k;++i) cin>>s[i];
		for(int i=0;i<n;++i) nxt[k][i]=k;
		for(int i=k-1;i>-1;--i)
		{
			for(int j=0;j<n;++j)
			{
				if(s[i]==p[j]) nxt[i][j]=i;
				else nxt[i][j]=nxt[i+1][j];
			}
		}
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=0;j<=n*(n-1)/2;++j) dp[i][j]=k;
		}
		for(int i=0;i<n;++i) dp[1<<i][0]=nxt[0][i];
		for(int i=1;i<(1<<n);++i)
		{
			for(int j=0;j<=n*(n-1)/2;++j)
			{
				if(dp[i][j]!=k)
				{
					for(int l=0;l<n;++l)
					{
						if(~i&(1<<l))
						{
							updata(dp[i|(1<<l)][j+cc[i&(g[l])]],nxt[dp[i][j]+1][l]);
						}
					}
				}
			}
		}
		for(int i=0;i<ans;++i) if(dp[(1<<n)-1][i]!=k) ans=i,la=mm;
	}
	ans=n*(n-1)/2-ans+1;
	if(ans==0){puts("Brand new problem!");}
	else
	{
		cout<<la<<endl;
		cout<<"[:";
		while(ans--) cout<<"|";
		cout<<":]\n";
	}
	cin>>n;
}