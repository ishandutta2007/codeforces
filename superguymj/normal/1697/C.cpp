#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=100005;
char s[N];
int n,a[N],b[N],A[N][3],B[N][3];
vector <int> S,T;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void solve()
{
	n=getint();
	scanf("%s",s+1);
	rep(i,1,n) a[i]=s[i]-'a';
	scanf("%s",s+1);
	rep(i,1,n) b[i]=s[i]-'a';
	rep(i,1,n)
	{
		rep(j,0,2) A[i][j]=A[i-1][j],B[i][j]=B[i-1][j];
		++A[i][a[i]],++B[i][b[i]];
	}
	rep(i,0,2) if(A[n][i]!=B[n][i])
	{
		puts("NO");
		return;
	}
	S.clear(),T.clear();
	rep(i,1,n) if(a[i]==0) S.pb(i);
	rep(i,1,n) if(b[i]==0) T.pb(i);
	int sz=S.size();
	rep(i,0,sz-1)
	{
		int x=S[i];
		int y=T[i];
		if(x>y || A[y][2]-A[x][2] || B[y][2]-B[x][2])
		{
			puts("NO");
			return;
		}
	}
	
	S.clear(),T.clear();
	rep(i,1,n) if(a[i]==2) S.pb(i);
	rep(i,1,n) if(b[i]==2) T.pb(i);
	sz=S.size();
	rep(i,0,sz-1)
	{
		int x=S[i];
		int y=T[i];
		if(x<y || A[x][0]-A[y][0] || B[x][0]-B[y][0])
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}	
	
int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}