#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1005;
typedef long long LL;
int n,A[5][5],B[5][5],a[5];
bool vis[5][5];

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
	memset(vis,0,sizeof(vis));
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	rep(i,1,n)
	{
		rep(j,0,4) a[j]=getint();
		rep(j,0,4) rep(k,j+1,4)
		{
			if(!a[j] && !a[k]) vis[j][k]=1;
			if(!a[j] && a[k]) ++A[j][k];
			if(a[j] && !a[k]) ++B[j][k];
		}
	}
	bool jdg=0;
	rep(i,0,4) rep(j,i+1,4) if(!vis[i][j])
		if(A[i][j]<=n/2 && B[i][j]<=n/2) jdg=1;
	if(jdg) puts("YES");
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--)
		solve();
	return 0;
}