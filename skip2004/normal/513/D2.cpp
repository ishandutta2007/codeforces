#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
#define pb push_back
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 1001000;

int n, c;
std::vector<int> le[N], ri[N];
int maxl[N], minr[N];
int max[N];
inline void no() { puts("IMPOSSIBLE"), exit(0); }
inline void up(int & x, int y) { if(x < y) x = y; }
inline void down(int & x, int y) { if(x > y) x = y; }
const int L=1<<20;
int seg[L<<1];
inline void upt(int pos,int v){
	for(seg[pos+=L]=v;pos>>=1;) seg[pos]=std::max(seg[pos<<1],seg[pos<<1|1]);
}
inline int ask(int l,int r){
	int res=0;
	l+=L-1,r+=L+1;
	for(;l+1!=r;l>>=1,r>>=1){
		if((l&1)==0)up(res,seg[l^1]);
		if((r&1)==1)up(res,seg[r^1]);
	}
	return res;
}
std::vector<int>res;
inline void solve(int l,int r){
	if(l>r)return;
	if(le[l].empty()) return res.pb(l),solve(l+1,r);
	if(ri[l].empty()) return solve(l+1,r),res.pb(l);
	int pos=ask(l+1,maxl[l]);
	if(pos>=minr[l])no();
	solve(l+1,pos);
	res.pb(l);
	solve(pos+1,r);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> c;
	rep(i, 1, n) minr[i] = n+1, max[i] = i;
	rep(i, 1, c) {
		int a, b;
		char buf[10];
		cin >> a >> b >> buf;
		if(b <= a) no();
		up(max[a], b);
		if(*buf == 'L') {
			up(maxl[a], b);
			le[a].pb(b);
		} else {
			down(minr[a], b);
			ri[a].pb(b);
		}
	}
	rep(i,1,n)if(maxl[i]>=minr[i])no();
	for(int i = n;i >= 1;--i) {
		up(max[i],ask(i,max[i]));
		upt(i,max[i]);
	}
	solve(1,n);
	for(int x:res)cout<<x<<' ';
}