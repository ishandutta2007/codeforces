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

const int maxn = 2e5 + 10, mod = 1e9 + 7;
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

int d1[maxn], d2[maxn], a[maxn];
vector<int> v[maxn];

void bfs(int u, int *h){
    queue<int> q;
    q.push(u);
    h[u] = 1;
    while(sz(q)){
	u = q.front();
	q.pop();
	for(int y : v[u])
	    if(h[y] == 0)
		h[y] = h[u] + 1, q.push(y);
    }	
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
	cin >> a[i];
    for(int i = 0; i < m; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    bfs(1, d1);
    bfs(n, d2);
    for(int i = 1; i <= n; i++)
	d1[i]--, d2[i]--;
    sort(a, a+k, [&](int i, int j){ return d1[i] - d2[i] < d1[j] - d2[j]; } );
    int mx = d1[ a[0] ], ans = 0;
    for(int i = 1; i < k; i++)
	ans = max(ans, mx + d2[ a[i] ] + 1), mx = max(mx, d1[ a[i] ]);
    ans = min(ans, d1[n]);
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")