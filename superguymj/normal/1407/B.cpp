#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=3005;
int T,n,a[N],ans[N];
bool vis[N];

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]),vis[i]=0;
		int mx=0;
		rep(i,1,n) mx=max(mx,a[i]);
		rep(i,1,n) if(a[i]==mx) {vis[i]=1; break;}
		int lst=mx;
		ans[1]=mx;
		rep(i,2,n)
		{
			mx=0;
			rep(j,1,n) if(!vis[j]) mx=max(mx,gcd(a[j],lst));
			rep(j,1,n) if(!vis[j] && mx==gcd(a[j],lst)) {vis[j]=1,ans[i]=a[j]; break;}
			lst=mx;
		}
		rep(i,1,n) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}