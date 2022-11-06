//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

ll n, q, s;
struct Node {
	ll l, r;
	mutable ll v;
	Node(ll x, ll y = -1, ll z = 0): l(x), r(y), v(z) {}
	bool operator < (const Node &a) const {return l < a.l;}
};
typedef set<Node>::iterator IT;
set<Node> ODT;
IT split(ll pos) {
	IT it = ODT.lower_bound(Node(pos));
	if(it != ODT.end() && it->l == pos) return it;
	--it;
	ll L = it->l, R = it->r, V = it->v;
	ODT.erase(it);
	ODT.insert(Node(L, pos-1, V));
	return ODT.insert(Node(pos, R, V)).first;
}
void assign_val(ll l, ll r, ll w) {
	IT itR = split(r+1), itL = split(l);
	for(IT it=itL;it!=itR;it++) s -= (it->r - it->l + 1) * it->v;
	if(w) s += r - l + 1;
	ODT.erase(itL, itR);
	ODT.insert(Node(l, r, w));
}

int main() {
	scanf("%lld%lld", &n, &q);
	s = n;
	ODT.insert(Node(1, n, 1));
	while(q--) {
		ll l, r, x;
		scanf("%lld%lld%lld", &l, &r, &x);
		assign_val(l, r, x-1);
		printf("%lld\n", s);
	}
    return 0;
}