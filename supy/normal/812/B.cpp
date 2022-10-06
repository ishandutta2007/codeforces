#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;

int n,m;
int a[20],l[20],r[20];
char s[20][150];
ll ans=1e16;

inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
void update() {
	ll tmp=n-1; //!!!!!!!!!!!!
	//1 l;  0 r
	rep(i,1,n-1) {
		if (a[i]!=a[i+1]) tmp+=m+1;
		else {
			if (a[i]==1) tmp+=2*r[i];
			else tmp+=2*(m-l[i]+1);
		}
	}
	if (a[n]==1) tmp+=r[n]; else tmp+=(m-l[n]+1);
//	printf("%d %lld\n",a[n],tmp);
	ans=min(ans,tmp);
}
void dfs(int k) {
	if (k>n) {
		update();
		return;
	}
	a[k]=1; dfs(k+1);
	a[k]=0; dfs(k+1);
}
int main()
{
//	freopen("1.in","r",stdin);
	read(n); read(m);
	per(i,n,1) scanf("%s",s[i]); //0..m+1
	rep(i,1,n) {
		l[i]=m+1; //init!!!!!!!!!!
		rep(j,1,m) if (s[i][j]=='1') r[i]=j;
		per(j,m,1) if (s[i][j]=='1') l[i]=j;
	//	printf("%d %d\n",l[i],r[i]);
	}
	while (n>1&&!r[n]) n--; //ending!!!
	if (n==1) {printf("%d",r[1]);return 0;}
	a[1]=1; dfs(2);
	printf("%lld",ans);
	return 0;
}