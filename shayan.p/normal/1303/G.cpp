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

const int maxn = 15e4 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

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

bool Q;
struct Line 
{
    mutable ll k, m, p;
    bool operator<(const Line& o) const 
    {
	return Q ? p < o.p : k < o.k;
    }
};
struct CHT : multiset<Line> 
{
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) 
    {
	// floored division
	return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) 
    {
	if (y == end())
	    {
		x->p = inf;
		return false;
	    }
	if (x->k == y->k)
	    x->p = x->m > y->m ? inf : -inf;
	else 
	    x->p = div(y->m - x->m, x->k - y->k);
	return x->p >= y->p;
    }
    void add(ll k, ll m) 
    {
	auto z = insert({k, m, 0}), y = z++, x = y;
	while (isect(y, z))
	    z = erase(z);
	if (x != begin() && isect(--x, y))
	    isect(x, y = erase(y));
	while ((y = x) != begin() && (--x)->p >= y->p)
	    isect(x, erase(y));
    }
    ll ask(ll x) 
    {
	assert(!empty());
	Q = 1; 
	auto l = *lower_bound({0, 0, x});
	Q = 0;
	return l.k * x + l.m;
    }
};
CHT cht;

ll ANS;
ll a[maxn];
int SZ[maxn];
bool mark[maxn];
vector<int> v[maxn];

vector<pll> vvv;
ll val[maxn], val2[maxn], sm[maxn];
int ROOTV;

void prep(int u, int h = 0, int par = -1){
    val[u]= (par == -1 ? 0 : val[par]) + 1ll * h * a[u];
    sm[u] = (par == -1 ? 0 : sm[par]) + a[u];
    val2[u] = (par == -1 ? 0 : val2[par]) + sm[u];
    ANS = max(ANS, val2[u]);
    ANS = max(ANS, val[u] + sm[u]);
    for(int y : v[u])
	if(y != par && mark[y] == 0)	    
	    prep(y, h+1, u);
}
void dfs(int u, int par, int h = 1){
    if(cht.empty() == 0)
	ANS = max(ANS, val2[u] + cht.ask(h+1));
    vvv.PB({sm[u] - ROOTV, val[u]});
    for(int y : v[u]){
	if(y != par && mark[y] == 0)
	    dfs(y, u, h+1);
    }
}
void go(int u){
    prep(u);
    cht.clear();
    for(int y : v[u])
	if(mark[y] == 0){
	    vvv.clear();
	    dfs(y, u);
	    for(auto p : vvv)
		cht.add(p.F, p.S);
	}
    reverse(v[u].begin(), v[u].end());
    cht.clear();
    for(int y : v[u])
	if(mark[y] == 0){
	    vvv.clear();
	    dfs(y, u);
	    for(auto p : vvv)
		cht.add(p.F, p.S);
	}

}

void dfsSz(int u, int par = -1){
    SZ[u] = 1;
    for(int y : v[u])
	if(y != par && mark[y] == 0)
	    dfsSz(y, u), SZ[u]+= SZ[y];
}
int center(int u, int N, int par = -1){
    for(int y : v[u])
	if(y != par && mark[y] == 0 && SZ[y] > N)
	    return center(y, N, u);
    return u;
}
void solve(int r){
    dfsSz(r);
    r = center(r, SZ[r]/2);
    ROOTV = a[r];
    go(r);
    mark[r] = 1;
    for(int y : v[r])
	if(mark[y] == 0)
	    solve(y);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i = 1; i <= n; i++){
	cin >> a[i];
    }
    solve(1);
    return cout << ANS << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")