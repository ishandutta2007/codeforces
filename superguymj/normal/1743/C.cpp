#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)
#define pb push_back

using namespace std;
const int N=200005,INF=2000000000;
char s[N];
int n,f[N][2],a[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	n=getint();
	scanf("%s",s+1);
	rep(i,1,n) a[i]=getint();
	f[0][0]=0;
	f[0][1]=-INF;
	rep(i,1,n)
	{
		rep(j,0,1) f[i][j]=-INF;
		f[i][0]=max(f[i][0],f[i-1][0]+a[i]*(s[i]=='1'));
		if(s[i]=='1') f[i][0]=max(f[i][0],f[i-1][1]);
		
		f[i][1]=max(f[i][1],f[i-1][0]+a[i]);
		if(s[i]=='1') f[i][1]=max(f[i][1],f[i-1][1]+a[i]);
	}
	printf("%d\n",f[n][0]);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}