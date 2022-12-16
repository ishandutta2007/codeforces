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

const int maxn = 2e5 + 10, SQ = 85, inf = 1e9;

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

struct suffix_array{
    string s;
    int rnk[20][maxn], srt[maxn];
    void build(string _s){
	s = _s;
	for(int i = 0; i < sz(s); i++){
	    rnk[0][i] = s[i];
	}
	iota(srt, srt + sz(s), 0);
	for(int i = 1; i < 20; i++){
	    auto cmp = [&](int a, int b){
			   if(rnk[i-1][a] != rnk[i-1][b])
			       return rnk[i-1][a] < rnk[i-1][b];
			   if(b + (1<<(i-1)) >= sz(s))
			       return false;
			   if(a + (1<<(i-1)) >= sz(s))
			       return true;
			   return rnk[i-1][a + (1<<(i-1))] < rnk[i-1][b + (1<<(i-1))];
		       };
	    sort(srt, srt + sz(s), cmp);	    
	    for(int j = 1; j < sz(s); j++)
		rnk[i][ srt[j] ] = rnk[i][ srt[j-1] ] + cmp(srt[j-1], srt[j]);
	}
    }
    int lcp(int a, int b){
	int ans = 0;
	for(int i = 19; i >= 0; i--)
	    if(a + (1<<i) <= sz(s) && b + (1<<i) <= sz(s) && rnk[i][a] == rnk[i][b])
		a+= 1<<i, b+= 1<<i, ans+= 1<<i;
	return ans;
    }
};
suffix_array suf;

int srt[maxn], val[maxn];
pii ans[maxn];

pii sp[20][maxn];

pii ask(int l, int r){
    if(l >= r)
	return {inf, inf};
    int id = 31 - __builtin_clz(r-l);
    return min(sp[id][l], sp[id][r - (1<<id)]);
}
void add1(int l, int r, int k, int x, int y, int i){
    int blk = l/k;
    int pt = min(r, (blk + 1) * k);
    ans[i] = min( ans[i], ask( max(blk * k + x, l), min(blk * k + y, pt) ) );
    l = pt;

    if(l == r)
	return;
    
    blk = r/k;
    pt = max(l, blk * k);
    ans[i] = min( ans[i], ask( max(blk * k + x, pt), min(blk * k + y, r) ) );
    r = pt;

    if(l == r)
	return;
    
    for(l/=k, r/=k; l < r; l++)
	ans[i] = min( ans[i], ask(l * k + x, l * k + y) );
}

vector< pair<pii, int> > tdo[SQ][SQ];
vector<pii> TDO[maxn];

void add2(int l, int r, int k, int x, int y, int i){
    for(int rm = x; rm < y; rm++)
	tdo[k][rm].PB({ {(l / k) + ((l % k) > rm), (r/k) + ((r % k) > rm) }, i });
}

int par[maxn];

void mrg(int a, int b){
    par[a]+= par[b];
    par[b] = a;
}
int fnd(int u){
    return par[u] < 0 ? u : par[u] = fnd(par[u]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s, t;
    cin >> s >> t;
    int n = sz(s);
    s+= t;
    suf.build(s);
    iota(srt, srt + n + 1, 0);
    auto chk = [&](int i, int j){
		   vector<pii> v1 = { {0, i}, {n, sz(s)}, {i, n} };
		   vector<pii> v2 = { {0, j}, {n, sz(s)}, {j, n} };
		   int pt1 = 0, pt2 = 0, L1 = 0, L2 = 0;
		   while(true){
		       while(L1 == v1[pt1].S){
			   ++pt1;
			   if(pt1 == sz(v1))
			       return false;
			   L1 = v1[pt1].F;
		       }
		       while(L2 == v2[pt2].S){
			   ++pt2;
			   if(pt2 == sz(v2))
			       return false;
			   L2 = v2[pt2].F;
		       }
		       int mn = min( v1[pt1].S - L1, v2[pt2].S - L2 );
		       int num = suf.lcp(L1, L2);
		       if(num < mn)
			   return s[L1 + num] < s[L2 + num];
		       else
			   L1+= mn, L2+= mn;
		   }
		   return false;
	       };
    int N = n+1;
    sort(srt, srt + N, chk);
    for(int i = 1; i < N; i++)
	val[ srt[i] ] = val[ srt[i-1] ] + chk(srt[i-1], srt[i]);
    for(int i = 0; i < N; i++)
	sp[0][i] = {val[i], i};
    for(int i = 1; i < 20; i++)
	for(int j = 0; j < N; j++)
	    sp[i][j] = min( sp[i-1][j], j + (1<<(i-1)) >= N ? (pii){n+10, n+10} : sp[i-1][j + (1<<(i-1))] );
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
	ans[i] = {n+10, n+10};
	int l, r, k, x, y;
	cin >> l >> r >> k >> x >> y;
	r++, y++;
	if(k >= SQ)
	    add1(l, r, k, x, y, i);
	else
	    add2(l, r, k, x, y, i);
    }
    for(int k = 1; k < SQ; k++){
	for(int rm = 0; rm < SQ; rm++){
	    if(tdo[k][rm].empty())
		continue;	    
	    vector<pii> vec;
	    vector<int> vec2;
	    for(int i = 0; i * k + rm < N; i++){
		vec.PB( {val[i * k + rm], i * k + rm} );
	    }
	    for(int i = 0; i < sz(vec); i++){
		par[i] = -1;
		TDO[i].clear();
	    }
	    for(auto x : tdo[k][rm]){
		if(x.F.F >= x.F.S)
		    continue;
		TDO[x.F.S - 1].PB({x.F.F, x.S});
	    }
	    for(int i = 0; i < sz(vec); i++){
		while(sz(vec2) && vec[ vec2.back() ] >= vec[i])
		    mrg(i, vec2.back()), vec2.pop_back();
		vec2.PB(i);
		for(auto [l, id] : TDO[i])
		    ans[id] = min(ans[id], vec[ fnd(l) ]);
	    }
	}
    }
    for(int i = 0; i < q; i++){
	cout << (ans[i].F == n+10 ? -1 : ans[i].S) << " ";
    }
    return cout << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")