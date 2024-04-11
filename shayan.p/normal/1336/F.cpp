// And you curse yourself for things you never done

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 15e4 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

vector<int> v[maxn];
int sp[20][maxn], h[maxn], SZ[maxn], tp[maxn];

void prep(int u, int par = 0){
    h[u] = h[par] + 1;
    sp[0][u] = par;
    SZ[u] = 1;
    for(int i = 1; i < 20; i++)
	sp[i][u] = sp[i-1][sp[i-1][u]];
    for(int y : v[u])
	if(y != par)
	    prep(y, u), SZ[u]+= SZ[y];
}
void prep2(int u, bool head = 1, int par = 0){
    tp[u] = (head ? u : tp[par]);
    int biggy = -1;
    for(int y : v[u]){
	if(y != par && (biggy == -1 || SZ[biggy] < SZ[y]))
	    biggy = y;
    }
    for(int y : v[u]){
	if(y == par)
	    continue;
	if(y == biggy)
	    prep2(y, 0, u);
	else
	    prep2(y, 1, u);
    }
}

int n, m;
pii p[maxn];

int cnt[maxn];
map<pii, vector<pii> > mp;

int go(int u, ll &ans, int par = 0){
    int num = cnt[u];
    for(int y : v[u]){
	if(y != par)
	    num+= go(y, ans, u);
    }
    ans+= 1ll * num * (num - 1) / 2;
    return num;
}
int lca(int a, int b){
    if(h[a] < h[b])
	swap(a, b);
    for(int i = 19; i >= 0; i--)
	if(h[ sp[i][a] ] >= h[b])
	    a = sp[i][a];
    if(a == b)
	return a;
    for(int i = 19; i >= 0; i--)
	if(sp[i][a] != sp[i][b])
	    a = sp[i][a], b = sp[i][b];
    return sp[0][a];
}
int up(int a, int k){
    for(int i = 0; i < 20; i++)
	if(bit(k, i))
	    a = sp[i][a];
    return a;
}

int arr[maxn];

void solve(vector<pii> &path, int k, ll &ans, int lc){
    vector< pair<pii, pii> > tdo;
    
    for(auto [a, b] : path){

	int start = h[a] - h[lc];
	    
	vector<pii> vec;
	while(h[ tp[a] ] > h[lc])
	    vec.PB({tp[a], h[a] - h[tp[a]] + 1}), a = sp[0][tp[a]];
	if(a != lc)
	    vec.PB({tp[a], h[a] - h[lc]});
	vec.PB({tp[lc], 1});
	int SZ = sz(vec);
	while(h[ tp[b] ] > h[lc])
	    vec.PB({tp[b], h[b] - h[tp[b]] + 1}), b = sp[0][tp[b]];
	if(b != lc)
	    vec.PB({tp[b], h[b] - h[lc]});
	reverse(vec.begin() + SZ, vec.end());
	
	pii L = {0, 0};
	pii R = {0, 0};
	while(R.F < sz(vec)){
	    if(R.S + vec[R.F].S <= k){
		R.S+= vec[R.F].S, R.F++;
	    }
	    else{
		R.S = k - R.S;
		break;
	    }		
	}	
	while(R.F < sz(vec)){
	    int mn = min(vec[L.F].S - L.S, vec[R.F].S - R.S);

	    pii _p = {vec[L.F].F, vec[R.F].F};
	    tdo.PB( {{start - mn, 1}, _p} );
	    tdo.PB( {{start, -1}, _p} );
	    
	    start-= mn;
	    L.S+= mn, R.S+= mn;
	    if(L.S == vec[L.F].S)
		L.F++, L.S = 0;
	    if(R.S == vec[R.F].S)
		R.F++, R.S = 0;
	}
    }
    sort(tdo.begin(), tdo.end());
    map<pii, int> cnt;
    int lst = 0;
    ll num = 0;
    for(auto p : tdo){
	ans+= num * (p.F.F - lst);
	int &x = cnt[p.S];
	num-= 1ll * x * (x-1) / 2;
	x+= p.F.S;
	num+= 1ll * x * (x-1) / 2;
	lst = p.F.F;
    }
}

ll solve(int k){
    mp.clear();
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < m; i++){
	int a = p[i].F, b = p[i].S, lc = lca(a, b);
	if(h[a] < h[b])
	    swap(a, b);
	if(h[a] - h[lc] >= k)
	    cnt[a]++, a = up(a, h[a] - h[lc] - k + 1), cnt[a]--;
	if(h[b] - h[lc] >= k)
	    cnt[b]++, b = up(b, h[b] - h[lc] - k + 1), cnt[b]--;
	int dis = h[a] + h[b] - 2 * h[lc];
	if(dis < k)
	    continue;
	assert(a != lc && b != lc);
	assert(h[a] - h[lc] < k);
	assert(h[b] - h[lc] < k);
	int A = up(a, h[a] - h[lc] - 1), B = up(b, h[b] - h[lc] - 1);
	assert(sp[0][A] == lc), assert(sp[0][B] == lc);
	if(A > B)
	    swap(A, B), swap(a, b);
	mp[{A, B}].PB({a, b});
    }
    ll ans = 0;
    go(1, ans);
    for(auto it : mp){
	solve(it.S, k, ans, sp[0][it.F.F]);
    }   
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    prep(1);
    prep2(1);
    for(int i = 0; i < m; i++){
	cin >> p[i].F >> p[i].S;
    }
    return cout << solve(k) - solve(k+1) << "\n", 0;
}