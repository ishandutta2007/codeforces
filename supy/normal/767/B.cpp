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
#define N 100005
int n;
ll a,b,t,ans1,ans2=1e13;
ll x[N],y[N]; //y:begin
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
void getans(ll l, ll r, ll s) {
	if (s>b||l>r) return; //!!!!!!!!
	if (s>=l&&s<=r) {ans1=s; ans2=0;}
	else if (s>r) {if (ans2>s-r){ans1=r; ans2=s-r;}}
	else {ans1=r; ans2=0;}
}
int main() {
//	freopen("1.in","r",stdin);
	read(a);read(b);read(t); b-=t; //tiyi
	scanf("%d",&n);
	rep(i,1,n) read(x[i]); x[n+1]=b+1;
	y[1]=x[1]<a ? a : x[1];
	rep(i,2,n) y[i]=max(y[i-1]+t,x[i]);
	rep(i,1,n) //printf("%lld %lld %lld\n",x[i],x[i+1]-1,y[i]+t);
		getans(x[i],x[i+1]-1,y[i]+t);
	getans(0,x[1]-1,a);
	printf("%lld",ans1);
	return 0;
}