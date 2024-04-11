#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=2005;
char s[N];
int n,f[N][N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int check(int i,int j,int tp)
{
	if(tp!=2) return tp;
	if(s[i]<s[j]) return 1;
	if(s[i]>s[j]) return 0;
	return 2;
}

void solve()
{
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n+1) f[i][i-1]=2;
	for(int i=2; i<=n; i+=2)
		rep(l,1,n-i+1)
		{
			int r=i+l-1;
			int a=check(l,l+1,f[l+2][r]);
			int b=check(l,r,f[l+1][r-1]);
			int c=check(r,l,f[l+1][r-1]);
			int d=check(r,r-1,f[l][r-2]);
			int x,y;

			if(a==0 || b==0) x=0;
			else if(a==2 || b==2) x=2;
			else x=1;

			if(c==0 || d==0) y=0;
			else if(c==2 || d==2) y=2;
			else y=1;

			if(x==1 || y==1) f[l][r]=1;
			else if(x==2 || y==2) f[l][r]=2;
			else f[l][r]=0;
	//		printf("%d %d %d\n",l,r,f[l][r]);
		}
	if(f[1][n]==1) puts("Alice");
	else if(f[1][n]==2) puts("Draw");
	else puts("Bob");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}