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
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 1004
const int mo = 1e9+7;
int n,a[27],ans1,ans2,ans3;
int p[N],f[N];
char s[N];
bool exist[27];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void getp(int i) {
//	memset(exist,0,sizeof(exist));
	int lst=n+1;
	for (p[i]=i; p[i]<=n; p[i]++) {
		lst=min(lst,i+a[s[p[i]]-'a']);
		if (p[i]>=lst) {break;}
	}
	p[i]--; //!!
//	printf("%d %d\n",i,p[i]);
}
inline void getans() {
	int pos=1;
	while (pos<=n) {ans3++; pos=p[pos]+1;}
	rep(i,1,n) ans2=max(ans2,p[i]-i+1);
	f[0]=1;
	rep(i,1,n) rep(j,0,i-1)
		if (p[j+1]>=i) f[i]=(f[i]+f[j])%mo;
	ans1=f[n];
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); scanf("%s",s+1);
	rep(i,0,25)read(a[i]);
//	puts("OwO");
	rep(i,1,n) getp(i);
	getans();
	printf("%d\n%d\n%d\n",ans1,ans2,ans3);
	return 0;
}