#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define MOD2 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void add2(int &a,int b) {a+=b; if(a>=MOD2) a-=MOD2;}
int n,m;
string str;
int main()
{
	scanf("%d%d",&n,&m);
	mat mp(n,vec(m)),dp1(n,vec(m)),dp2(n,vec(m)),dp3(n,vec(m)),dp4(n,vec(m));
	for(int i=0;i<n;i++)
	{
		cin>>str;
		for(int j=0;j<m;j++) if(str[j]=='.') mp[i][j]=1; else mp[i][j]=0;
	}
	dp1[0][0]=dp2[n-1][m-1]=dp3[0][0]=dp4[n-1][m-1]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]==0) {dp1[i][j]=dp3[i][j]=0; continue;}
			if(i>0) add(dp1[i][j],dp1[i-1][j]),add2(dp3[i][j],dp3[i-1][j]);
			if(j>0) add(dp1[i][j],dp1[i][j-1]),add2(dp3[i][j],dp3[i][j-1]);
		}
	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--)
		{
			if(mp[i][j]==0) {dp2[i][j]=dp4[i][j]=0; continue;}
			if(i<n-1) add(dp2[i][j],dp2[i+1][j]),add2(dp4[i][j],dp4[i+1][j]);
			if(j<m-1) add(dp2[i][j],dp2[i][j+1]),add2(dp4[i][j],dp4[i][j+1]);
		}
	int ways1=dp1[n-1][m-1],ways2=dp3[n-1][m-1];
	if(dp1[n-1][m-1]==0&&dp3[n-1][m-1]==0) puts("0");
	else 
	{
		bool f=true;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(i==0&&j==0) continue;
				if(i==n-1&&j==m-1) continue;
				if(1LL*dp1[i][j]*dp2[i][j]%MOD==ways1&&1LL*dp3[i][j]*dp4[i][j]%MOD2==ways2) f=false;
			}
		}
		if(f) puts("2"); else puts("1");
	}
    return 0;
}