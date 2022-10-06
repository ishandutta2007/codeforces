#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 205000;
int n,m,r,k;
ll a[N],b[N];
ll ans;
priority_queue<pair<ll,Pii> > heap;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(ll a, ll b) {return a>b;}
int main() {
	read(n); read(m); read(r); read(k);
	rep(i,1,n) {
		int L=(i-r+1>=1)?i-r+1:1,R=(i+r-1<=n)?i:n-r+1;
		a[i]=R-L+1;
	}
	rep(i,1,m) {
		int L=(i-r+1>=1)?i-r+1:1,R=(i+r-1<=m)?i:m-r+1;
		b[i]=R-L+1;
	}
	sort(a+1,a+n+1,cmp); sort(b+1,b+m+1,cmp);
	rep(i,1,n) heap.push(pair<ll,Pii>(a[i]*b[1],Pii(i,1)));
	while (k--) {
		pair<ll,Pii> u=heap.top(); heap.pop();
		ans+=u.fi; Pii v=u.se; if (v.se<m) {
			v.se++; heap.push(pair<ll,Pii>(a[v.fi]*b[v.se],Pii(v.fi,v.se)));
		}
	}
	printf("%.10lf",(double)ans/(n-r+1)/(m-r+1));
	return 0;
} //12 17 9 40