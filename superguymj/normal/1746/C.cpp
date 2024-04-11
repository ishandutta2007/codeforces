#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005;
int n,a[N],p[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	repd(i,n,1) a[i]=a[i]-a[i-1];
	rep(i,1,n) p[i]=i;
	sort(p+1,p+1+n,cmp);
	reverse(p+1,p+1+n);
	rep(i,1,n) printf("%d ",p[i]);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}