#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5e5 + 10;

struct DSU{
    pii par[maxn];
    vector<pair<int, pii>> vec;
    vector<int> rec;
    
    DSU(){
	fill(par, par + maxn, (pii){-1, 0});
    }
    void record(){
	rec.PB(sz(vec));
    }
    void undo(){
	int SZ = rec.back();
	rec.pop_back();
	while(sz(vec) > SZ){
	    par[vec.back().F] = vec.back().S;
	    vec.pop_back();
	}
    }
    pii fnd(int u){
	if(par[u].F < 0)
	    return {u, 0};
	pii p = fnd(par[u].F);
	p.S^= par[u].S;
	return p;
    }
    bool mrg(int a, int b){
	pii A = fnd(a), B = fnd(b);
	if(A.F == B.F){
	    if(A.S == B.S)
		return false;
	    else
		return true;
	}
	if(par[A.F].F > par[B.F].F)
	    swap(A, B);
	vec.PB({A.F, par[A.F]});
	vec.PB({B.F, par[B.F]});
	par[A.F].F+= par[B.F].F;
	par[B.F].F = A.F;
	par[B.F].S = A.S ^ B.S ^ 1;
	return true;
    }
};
DSU dsu;
map<pair<int, int>, vector<pair<int, int>>> mp;
int col[maxn];
bool bad[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
	cin >> col[i];
    }
    for(int i = 1; i <= m; i++){
	int a, b;
	cin >> a >> b;
	if(col[a] > col[b])
	    swap(a, b);
	if(col[a] == col[b]){
	    bad[col[a]]|= !dsu.mrg(a, b);
	}
	else{
	    mp[{col[a], col[b]}].PB({a, b});
	}
    }
    int good = 0;
    for(int i = 1; i <= k; i++){
	good+= !bad[i];
    }
    ll ans = 1ll * good * (good-1) / 2;
    for(auto &it : mp){
	if(bad[it.F.F] || bad[it.F.S])
	    continue;
	bool is_bad = 0;
	dsu.record();
	for(pii p : it.S){
	    is_bad|= !dsu.mrg(p.F, p.S);
	}
	ans-= is_bad;
	dsu.undo();
    }
    return cout << ans << endl, 0;
}