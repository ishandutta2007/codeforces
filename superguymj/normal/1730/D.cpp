#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define pb push_back

using namespace std;
const int N=100005;
int n,c[30][30];
char s[N],t[N];

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
	scanf("%s",t+1);
	rep(i,0,25) rep(j,i,25) c[i][j]=0;
	rep(i,1,n)
	{
		int x=s[i]-'a',y=t[n-i+1]-'a';
		if(x>y) swap(x,y);
		c[x][y]^=1;
	}
	int ans=0,x,y;
	rep(i,0,25) rep(j,i,25) if(c[i][j]) ++ans,x=i,y=j;
	if(ans==0) puts("YES");
	else if(ans==1)
	{
		if(x==y) puts("YES");
		else puts("NO");
	}		
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}