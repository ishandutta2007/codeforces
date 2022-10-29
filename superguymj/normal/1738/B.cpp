#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,k,a[N];

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
	n=getint(),k=getint();
	rep(i,1,k) a[i]=getint();
	if(k==1) {puts("YES"); return;}
	repd(i,k,2) a[i]-=a[i-1];
	rep(i,2,k-1) if(a[i]>a[i+1]) {puts("NO"); return;}
	int tot=a[1],A=a[2],B;
	if(tot>=0) B=(tot+n-k)/(n-k+1);
	else B=-(-tot)/(n-k+1);
	if(B<=A) puts("YES");
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}