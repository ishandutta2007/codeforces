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

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 2e9 + 10;

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

pii px[maxn], py[maxn];
pair<pii, int> p[maxn];

int val[4 * maxn], lz[4 * maxn], n, m, k;

void shift(int l, int r, int id){
    val[id]+= lz[id];
    if(r-l > 1){
	lz[2*id]+= lz[id];
	lz[2*id+1]+= lz[id];
    }
    lz[id] = 0;
}
void add(int f, int s, int x, int l = 0, int r = m, int id = 1){
    if(f >= s || l >= r)
	return;
    shift(l, r, id);
    if(s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	lz[id] = x;
	shift(l, r, id);
	return;
    }
    int mid = (l+r) >> 1;
    add(f, s, x, l, mid, 2*id);
    add(f, s, x, mid, r, 2*id+1);
    val[id] = max(val[2*id], val[2*id+1]);
}
int ask(){
    return val[1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
	cin >> px[i].F >> px[i].S;
    for(int i = 0; i < m; i++)
	cin >> py[i].F >> py[i].S;
    for(int i = 0; i < k; i++)
	cin >> p[i].F.F >> p[i].F.S >> p[i].S;
    sort(px, px+n), sort(py, py+m), sort(p, p+k);
    for(int i = 0; i < m; i++)
	add(i, i+1, -py[i].S);
    int ans = -inf;
    int pt = 0;
    for(int i = 0; i < n; i++){
	while(pt < k && p[pt].F.F < px[i].F)
	    add(upper_bound(py, py+m, (pii){p[pt].F.S, inf}) - py, m, p[pt].S), pt++;
	ans = max(ans, -px[i].S + ask());
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")