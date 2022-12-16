// hello darkness my old friend, I've come to talk with you again

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

struct DSU{
    pii par[maxn];
    vector< pair<int, pii> > sv;
    vector<int> rec;
    DSU(){
	for(int i = 0; i < maxn; i++)
	    par[i] = {-1, 0};
    }
    void record(){
	rec.PB(sz(sv));
    }
    void undo(){
	assert(sz(rec));
	int t = rec.back();
	rec.pop_back();
	while(sz(sv) > t){
	    par[ sv.back().F ] = sv.back().S;
	    sv.pop_back();
	}
    }
    pii fnd(int u){
	if(par[u].F < 0)
	    return {u, 0};
	pii p = fnd(par[u].F);
	p.S^= par[u].S;
	return p;
    }
    int mrg(int a, int b){
	pii A = fnd(a), B = fnd(b);
	if(A.F == B.F){
	    if(A.S == B.S)
		return -1;
	    else
		return 0;
	}
	if(par[A.F] > par[B.F])
	    swap(A, B);
	sv.PB({A.F, par[A.F]});
	sv.PB({B.F, par[B.F]});
	par[A.F].F += par[B.F].F;
	par[B.F] = { A.F, A.S ^ B.S ^ 1 };
	return 1;
    }
};
DSU dsu;

pii p[maxn];
int f[maxn];

int AMAL;

void solve(int l, int r, int L, int R){
    if(l > r)
	return;
    
    AMAL+= r-l + R - L;
    assert(AMAL <= 40 * maxn);
    
    L = max(L, l);
    dsu.record();
    int mid = (l+r) >> 1;
    for(int i = l; i < mid; i++)
	dsu.mrg(p[i].F, p[i].S);
    f[mid] = R;
    for(int i = R-1; i >= mid && i >= L; i--){
	if(dsu.mrg(p[i].F, p[i].S) == -1)
	    break;
	f[mid] = i;
    }
    dsu.undo();
    
    dsu.record();
    for(int i = R-1; i >= f[mid]; i--)
	dsu.mrg(p[i].F, p[i].S);
    solve(l, mid-1, L, f[mid]);
    dsu.undo();

    dsu.record();
    for(int i = l; i <= mid; i++)
	dsu.mrg(p[i].F, p[i].S);
    solve(mid+1, r, f[mid], R);
    dsu.undo();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
	cin >> p[i].F >> p[i].S;
    }
    dsu.record();
    int LSTI = 0;
    for(int i = 0; i < m; i++){
	LSTI = i;
	if(dsu.mrg(p[i].F, p[i].S) == -1)
	    break;
    }
    dsu.undo();
    solve(0, LSTI, 0, m);
    while(q--){
	int l, r;
	cin >> l >> r;
	cout << ((l-1 <= LSTI && f[l-1] <= r) ? "NO\n" : "YES\n");
    }
    return 0;
}