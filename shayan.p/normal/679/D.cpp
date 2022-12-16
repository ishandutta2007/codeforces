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

const int maxn = 410, mod = 1e9 + 7;
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

bool adj[maxn][maxn];
int dis[maxn][maxn], deg[maxn];
double val[maxn], arr[maxn];

vector<int> verts[maxn];
int h[maxn], n;

bool seen[maxn];

void bfs(int u){
    queue<int> q;
    memset(h, 0, sizeof h);
    q.push(u);
    h[u] = 1;
    while(sz(q)){
	u = q.front();
	q.pop();
	for(int i = 0; i < n; i++)
	    if(adj[u][i] && h[i] == 0)
		h[i] = h[u] + 1, q.push(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int m;
    cin >> n >> m;
    while(m--){
	int a, b;
	cin >> a >> b;
	--a, --b;
	adj[a][b] = adj[b][a] = 1;
    }
    for(int i = 0; i < n; i++){
	bfs(i);
	memcpy(dis[i], h, sizeof h);
	for(int j = 0; j < n; j++)
	    deg[i]+= adj[i][j];
    }
    
    double ans = 0;
    for(int u = 0; u < n; u++){
	for(int i = 0; i <= n; i++)
	    verts[i].clear();
	bfs(u);
	for(int i = 0; i < n; i++)
	    verts[ h[i] ].PB(i);
	double num = 0;
	for(int i = 1; i <= n; i++){
	    if(verts[i].empty())
		continue;
	    vector<int> vec;
	    for(int x : verts[i-1])
		vec.PB(x), arr[x] = 0;
	    for(int x : verts[i])
		vec.PB(x), arr[x] = 0;
	    for(int x : verts[i+1])
		vec.PB(x), arr[x] = 0;
	    for(int x : verts[i])
		for(int y = 0; y < n; y++)
		    if(adj[x][y])
			arr[y]+= 1.0 / deg[x];
	    double num2 = 0;
	    for(int y = 0; y < n; y++){
		for(int w : vec)
		    val[ dis[y][w] ] = 0, seen[ dis[y][w] ] = 0;
		for(int w : vec)
		    val[ dis[y][w] ] = max( val[ dis[y][w] ], arr[w] );
		double num3 = 0;
		for(int w : vec)
		    if(seen[ dis[y][w] ] == 0)
			seen[ dis[y][w] ] = 1, num3+= val[ dis[y][w] ];
		num2 = max(num2, num3);
	    }
	    num+= max(1.0, num2);
	}
	ans = max(ans, num / n);
    }
    return cout << setprecision(7) << fixed << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")