// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 5e5 + 10;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

struct DSU{
    pii par[maxn];
    vector<pair<int, pii> > vec;
    vector<int> rec;
    DSU(){
	for(int i = 0; i < maxn; i++)
	    par[i].F = -1;
    }
    void record(){
	rec.PB(sz(vec));
    }
    void undo(){
	int SZ = rec.back();
	for(rec.pop_back(); sz(vec) > SZ; vec.pop_back())
	    par[ vec.back().F ] = vec.back().S;
    }
    pii fnd(int u){
	if(par[u].F < 0)
	    return {u, 0};
	pii p = fnd( par[u].F );
	p.S ^= par[u].S;
	return p;
    }
    bool mrg(int a, int b){
	pii A = fnd(a), B = fnd(b);
	if(A.F == B.F)
	    return A.S != B.S;
	if(par[A.F] > par[B.F])
	    swap(A, B);
	vec.PB({A.F, par[A.F]});
	vec.PB({B.F, par[B.F]});
	par[A.F].F += par[B.F].F;
	par[B.F].F = A.F;
	par[B.F].S = A.S ^ B.S ^ 1;
	return 1;
    }
};
DSU dsu[55];

vector<int> edges[maxn];
vector<int> qur[4 * maxn];
int A[maxn], B[maxn], ID[maxn], C[maxn], NC[maxn];
bool ans[maxn];
int q;

void add(int f, int s, int l = 0, int r = q, int id = 1){
    if(f >= s || l >= r || s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	qur[id].PB(f-1);
	return;
    }
    int mid = (l+r) >> 1;
    add(f, s, l, mid, 2*id);
    add(f, s, mid, r, 2*id+1);
}
void solve(int l = 0, int r = q, int id = 1){
    for(int i = 0; i < 55; i++)
	dsu[i].record();
    for(auto p : qur[id]){
	if(C[p] == 0)
	    continue;
	dsu[ C[p] ].mrg( A[ ID[p] ], B[ ID[p] ] );
    }
    if(r-l == 1){
	assert(C[l]);
	if( dsu[ C[l] ].mrg( A[ ID[l] ], B[ ID[l] ] ) ){	    
	    ans[l] = 0;
	}
	else{
	    C[l] = NC[ ID[l] ];
	    ans[l] = 1;
	}
	NC[ ID[l] ] = C[l];
    }
    else{	
	int mid = (l+r) >> 1;
	solve(l, mid, 2*id);
	solve(mid, r, 2*id+1);
    }
    for(int i = 0; i < 55; i++)
	dsu[i].undo();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m, k;
    cin >> n >> m >> k >> q;
    for(int i = 0; i < m; i++){
	cin >> A[i] >> B[i];
    }
    for(int i = 0; i < q; i++){
	cin >> ID[i] >> C[i];
	edges[ --ID[i] ].PB(i);
    }
    for(int i = 0; i < m; i++){
	for(int j = 0; j < sz(edges[i]); j++)
	    add(edges[i][j]+1, j == sz(edges[i])-1 ? q : edges[i][j+1]);
    }
    solve();
    for(int i = 0; i < q; i++){
	cout << (ans[i] ? "NO\n" : "YES\n");
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")