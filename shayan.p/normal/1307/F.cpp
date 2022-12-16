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

const int maxn = 4e5 + 10, mod = 1e9 + 7, inf = 1e9;

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

bool is[maxn];
priority_queue<pii, vector<pii>, greater<pii> > pq[maxn];
vector<int> v[maxn];
int h[maxn], sp[20][maxn];
int n, k;

vector<int> vert[maxn];
int col[maxn];

void init(){
    for(int i = 0; i < maxn; i++)
	col[i] = i, vert[i].PB(i);
}
void mrg(int a, int b){
    if(col[a] == col[b])
	return;
    a = col[a], b = col[b];
    if(sz(vert[a]) < sz(vert[b]))
	swap(a, b);
    for(int x : vert[b])
	col[x] = a, vert[a].PB(x);
    vert[b].clear();
}

void dfs(int u, int par = -1){
    h[u] = par == -1 ? 1 : (h[par] +1);
    sp[0][u] = par;
    for(int i = 1; i < 20; i++){
	sp[i][u] = -1;
	if(sp[i-1][u] != -1)
	    sp[i][u] = sp[i-1][ sp[i-1][u] ];	
    }
    
    if(is[u])
	pq[u].push({h[u], u});
    for(int y : v[u]){
	if(y != par){
	    dfs(y, u);
	    pii tp1 = {inf, inf}, tp2 = {inf, inf};
	    if(!pq[u].empty())
		tp1 = pq[u].top();
	    if(!pq[y].empty())
		tp2 = pq[y].top();
	    if(tp1.F != inf){
		while(!pq[y].empty() && tp1.F + pq[y].top().F - h[u] - h[u] <= k)
		    mrg(pq[y].top().S, tp1.S), pq[y].pop();
	    }
	    if(tp2.F != inf){
		while(!pq[u].empty() && tp2.F + pq[u].top().F - h[u] - h[u] <= k)
		    mrg(pq[u].top().S, tp2.S), pq[u].pop();
	    }
	    if(tp1 > tp2)
		swap(tp1, tp2);
	    pq[u].push(tp1); //
	    
	    if(sz(pq[u]) < sz(pq[y]))
		swap(pq[u], pq[y]); // 
	    while(sz(pq[y]))
		pq[u].push(pq[y].top()), pq[y].pop();
	}
    }
}

int lca(int a, int b){
    if(h[a] < h[b])
	swap(a, b);
    for(int i = 19; i >= 0; i--){
	if(sp[i][a] != -1 && h[ sp[i][a] ] >= h[b])
	    a = sp[i][a];	
    }
    if(a == b)
	return a;
    for(int i = 19; i >= 0; i--){
	if(sp[i][a] != sp[i][b])
	    a = sp[i][a], b = sp[i][b];
    }
    return sp[0][a];
}
int up(int a, int k){
    for(int i = 0; i < 20; i++)
	if(bit(k, i))
	    a = sp[i][a];
    return a;
}

int near[maxn];
int bh[maxn];

void bfs(vector<int> &vec, int c){
    queue<int> q;
    for(int x : vec)
	bh[x] = 0, near[x] = c, q.push(x);
    while(sz(q)){
	int u = q.front();
	q.pop();
	if(bh[u] == (k/2))
	    continue;
	for(int y : v[u]){
	    if(bh[y] == -1)
		bh[y] = bh[u] + 1, near[y] = c, q.push(y);
	}
    }
}

int calc(int u){
    return bh[u] == -1 ? -1 : near[u];
}
bool solve(int a, int b){
    int lc = lca(a, b);
    int dis = h[a] + h[b] - h[lc] - h[lc];
    if(dis <= k)
	return 1;
    int A = -1, B = -1;
    if(h[a] - h[lc] >= (k/2))
	A = calc( up(a, k/2) );
    else
	A = calc( up(b, dis - (k/2)) );
    if(h[b] - h[lc] >= (k/2))
	B = calc( up(b, k/2) );
    else
	B = calc( up(a, dis - (k/2)) );
    return A != -1 && B != -1 && A == B;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    init();
    
    int r;
    cin >> n >> k >> r;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	--a, --b;
	v[a].PB(n+i);
	v[n+i].PB(a);
	v[b].PB(n+i);
	v[n+i].PB(b);
   }
    n+= n-1;
    k*=2;

    for(int i = 0; i < r; i++){
	int a;
	cin >> a;
	is[--a] = 1;
    }
    dfs(0);

    memset(bh, -1, sizeof bh);
    
    for(int i = 0; i < maxn; i++){
	if(vert[i].empty())
	    continue;
	if(is[ vert[i].back() ])
	    bfs(vert[i], i);
    }
    
    int q;
    cin >> q;
    while(q--){
	int a, b;
	cin >> a >> b;
	cout << (solve(--a, --b) ? "YES\n" : "NO\n");
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")