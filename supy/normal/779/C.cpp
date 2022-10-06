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
#define N 200005
int n,k;
struct P {
	int a,b,dis;
} s[N];
int ans;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(P x, P y) {return x.dis<y.dis;}
int main() {
	read(n); read(k);
	rep(i,1,n) read(s[i].a);
	rep(i,1,n) read(s[i].b);
	rep(i,1,n) s[i].dis=s[i].a-s[i].b;
	sort(s+1,s+n+1,cmp);
	rep(i,1,k) ans+=s[i].a;
	rep(i,k+1,n) if (s[i].dis<0) ans+=s[i].a; else ans+=s[i].b;
	printf("%d",ans);
	return 0;
}