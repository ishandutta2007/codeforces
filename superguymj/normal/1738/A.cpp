#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,a[N],b[N];
int cnt[2],stk[2][N];
LL ans,Ans;

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
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) b[i]=getint();
	cnt[0]=cnt[1]=0;
	rep(i,1,n)
		stk[a[i]][++cnt[a[i]]]=b[i];
	sort(stk[0]+1,stk[0]+1+cnt[0]);
	sort(stk[1]+1,stk[1]+1+cnt[1]);
	Ans=0;
	rep(i,0,1)
	{
		ans=0;
		rep(j,1,n) ans+=b[j];
		int A=cnt[0],B=cnt[1];
		if(i) --B;
		else --A;
		if(A<0 || B<0) continue;
		int mn=min(A,B);
		int _A=mn,_B=mn;
		if(i) _A=min(A,mn+1);
		else _B=min(B,mn+1);
		rep(j,cnt[0]-_A+1,cnt[0]) ans+=stk[0][j];
		rep(j,cnt[1]-_B+1,cnt[1]) ans+=stk[1][j];
		Ans=max(Ans,ans);
	}
	printf("%lld\n",Ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}