#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define FOR(i,a,b,p) for (int i=a; i<=b; i+=p)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 100005
int n,k,x;
int a[N];
int buc[2005];
int rec[15][N];
bool repe=0;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int judge(int k) {
	rep(i,1,k) {
		bool same=1;
		rep(j,1,n) if (a[j]!=rec[i][j]) {same=0;break;}
		if (same) return i;
	}
	return -1;
}
void trans(int kase) {
	FOR(i,1,n,2) a[i]^=x;
	memset(buc,0,sizeof(buc));
	rep(i,1,n) buc[a[i]]++; int l=0;
	rep(i,0,1023) while (buc[i]) {a[++l]=i;buc[i]--;} //careful
//	printf("%d:",kase);rep(i,1,n) printf("%d ",a[i]); puts(""); //del!!
	int tmp=judge(kase-1);
	if (tmp>=1) {
		repe=1; int p=(k-kase)%(kase-tmp)+tmp;
		rep(i,1,n) a[i]=rec[p][i];
	}
	rep(i,1,n) rec[kase][i]=a[i];
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(k); read(x);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
	rep(i,1,k) if (!repe) trans(i);
	/*if (k>=1) {
		rep(i,1,n) a[i]=max(a[i],a[i]^x);
	}*/
	int mx=0,mn=1e8;
	rep(i,1,n) {mx=max(mx,a[i]); mn=min(mn,a[i]);}
	printf("%d %d",mx,mn);
	return 0;
}