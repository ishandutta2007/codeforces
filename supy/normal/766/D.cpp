#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
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
map<string,int> Map;
const int N = 2e5+5;
int n,m,q,f[N],v[N];
inline int find(int x) {
	if (f[x]==x) return x;
	int fa=f[x];
	f[x]=find(f[x]); v[x]+=v[fa];
	return f[x];
}
inline bool merge(int x, int y, int op) {
//	printf("%d %d %d\n",x,y,op);
	int fx=find(x),fy=find(y);
//	puts("OwO");
	if (fx!=fy) {f[fx]=fy; v[fx]=(op+v[y]-v[x]+100000)&1; return 1;}
	return ((abs(v[x]-v[y]))&1) == op;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int solve(int a, int b) {
	int fx=find(a),fy=find(b);
	if (fx!=fy) return 3;
	if (abs(v[a]-v[b])&1) return 2;
	return 1;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);read(m);read(q);
	string s,s1,s2;
	rep(i,1,n){cin>>s; Map[s]=i;}
	rep(i,1,n) f[i]=i;
	while (m--) {
		int op,x,y; read(op); cin>>s1>>s2;
		x=Map[s1]; y=Map[s2];
		if (merge(x,y,op-1)) puts("YES");
		else puts("NO");
	}
	while (q--) {
		cin>>s1>>s2;
		printf("%d\n",solve(Map[s1],Map[s2]));
	}
	return 0;
}