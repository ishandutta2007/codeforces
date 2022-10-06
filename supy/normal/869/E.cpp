#include<cstdio>
#include<iostream>
#define MID ((L+R)>>1)
#define rep(i,a,b) for (int i=a; i<=b; i++)
const int N = 100004, M = 12000200;
typedef long long ll;
using namespace std;
typedef pair<ll,ll> Pll;
int n,m,q;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
struct Seg {
	int size,lc[M],rc[M];
	ll sum[M];
	inline void init() {size=max(n,m);}
	inline void add(int k, int p, int v, int L, int R) {
		sum[k]+=v;
		if (L==R) return;
		if (p<=MID) {if (!lc[k]) lc[k]=++size; add(lc[k],p,v,L,MID);}
		else {if (!rc[k]) rc[k]=++size; add(rc[k],p,v,MID+1,R);}
	}
	inline ll query(int k, int l, int r, int L, int R) {
		if (!k) return 0;
		if (l==L && r==R) return sum[k];
		if (r<=MID) return query(lc[k],l,r,L,MID);
		if (l>=MID+1) return query(rc[k],l,r,MID+1,R);
		return query(lc[k],l,MID,L,MID)+query(rc[k],MID+1,r,MID+1,R);
	}
} tree1,tree2;
struct B {
	inline void add(int x, int y, int v1, int v2) {
		if (x<1||x>n||y<1||y>m) return;
		while (x<=n) {tree1.add(x,y,v1,1,m); tree2.add(x,y,v2,1,m); x+=x&-x;}
	}
	inline Pll query(int x, int l, int r) { //<=x, l<=<=r
		Pll res(0,0);
		while (x) {res.first+=tree1.query(x,l,r,1,m); res.second+=tree2.query(x,l,r,1,m); x-=x&-x;}
		return res;
	}
} BIT;
inline void add(int x, int y, int v1, int v2) {BIT.add(x,y,v1,v2);}
inline void add(int x1, int y1, int x2, int y2, int v1, int v2) {
	add(x1,y1,v1,v2); add(x1,y2+1,-v1,-v2);
	add(x2+1,y1,-v1,-v2); add(x2+1,y2+1,v1,v2);
}
inline Pll query(int x, int y) {
	return BIT.query(x,1,y);
}
inline int getnum(int a1, int b1, int a2, int b2) {
	int mo = 1e9+7;
	return (((((ll)a1*10007+b1)%mo*10007+a2)%mo*10007+b2)%mo);
}
inline int getnum1(int a1, int b1, int a2, int b2) {
	int mo = 70000007;
	return (((((ll)a1*30007+b1)%mo*30007+a2)%mo*30007+b2)%mo);
}
int main() {
	//tree.init(); add
	read(n); read(m); read(q); tree1.init(); tree2.init();
	while (q--) {
		int op,a1,b1,a2,b2;
		read(op); read(a1); read(b1); read(a2); read(b2);
		int s1=getnum(a1,b1,a2,b2),s2=getnum1(a1,b1,a2,b2);
		if (op==1) add(a1,b1,a2,b2,s1,s2);
		if (op==2) add(a1,b1,a2,b2,-s1,-s2);
		if (op==3) {
			Pll x=query(a1,b1),y=query(a2,b2);
		//	printf("[%lld %lld %lld %lld]\n",x.first,x.second,y.first,y.second);
			printf("%s\n",x==y ? "Yes" : "No");
		}
	}
	return 0;
}