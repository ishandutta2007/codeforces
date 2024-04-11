#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
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
const int N = 254000; //M = 62
char str[N],ans[N];
int n,m,a[N];
struct Tree {
	int l,r,sum;
} tree[N<<2];
set<int> Set[70];
inline void build(int k, int l, int r) {
	tree[k].l=l; tree[k].r=r; tree[k].sum=r-l+1;
	if (l==r) return; int MID=(l+r)>>1;
	build(lc(k),l,MID); build(rc(k),MID+1,r);
}
inline int query(int k, int lst) {
	if (tree[k].l==tree[k].r) return tree[k].l;
	if (lst<=tree[lc(k)].sum) return query(lc(k),lst);
	return query(rc(k),lst-tree[lc(k)].sum);
}
inline void modify(int k, int p) {
	tree[k].sum--; if (tree[k].l==tree[k].r) return;
	if (p<=tree[lc(k)].r) modify(lc(k),p);
	else modify(rc(k),p);
}
inline void Query(int L, int R, int v) {
	int l=(L<=tree[1].sum) ? query(1,L) : n;
	int r=(R<=tree[1].sum) ? query(1,R) : n;
//	printf("%d %d\n",l,r);
	set<int> ::iterator a=Set[v].lower_bound(l),b=Set[v].upper_bound(r),it,it1;
//	puts("OwO"); 
	if (a==b || b==Set[v].begin()) return;
//	puts("OwO");
	for (it=a; it!=b;) {
		it1=it; it++; int pos=*it1;
		modify(1,pos);
		Set[v].erase(it1);
	}
}


inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int dy(char c) {
	if (c<='9') return c-'0'+1;
	if (c<='Z') return 11+c-'A';
	return c-'a'+37;
}

inline void print(int k) {
	if (tree[k].l==tree[k].r && tree[k].sum>0) {printf("%c",str[tree[k].l]); return;}
	if (tree[lc(k)].sum>0) print(lc(k));
	if (tree[rc(k)].sum>0) print(rc(k));
}
int main() { //freopen("1.in","r",stdin);//!!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1!!!!!!1
	read(n); read(m); scanf("%s",str+1);
	rep(i,1,n) a[i]=dy(str[i]),Set[a[i]].insert(i);
	build(1,1,n);
//	printf("%d %d %d %d %d\n",'0','A','Z','a','z');
	while (m--) {
		int l,r; char ss[3]; read(l); read(r);
		scanf("%s",ss); int v=dy(ss[0]);
		Query(l,r,v);
	}
	print(1);
	return 0;
}