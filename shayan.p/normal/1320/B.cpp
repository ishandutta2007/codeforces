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

int a[maxn];
vector<int> v[maxn], g[maxn];
int h[maxn];
bool is[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	int b, a;
	cin >> b >> a;
	v[a].PB(b);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
	cin >> a[i];
    }
    reverse(a, a+k);

    queue<int> q;
    q.push(a[0]);
    h[a[0]] = 1;
    while(sz(q)){
	int u = q.front();
	q.pop();
	for(int y : v[u]){
	    if(h[y] == 0)
		h[y] = h[u] + 1, q.push(y);
	    else if(h[y] == h[u]+1)
		is[y] = 1;
	}
    }
    for(int u = 1; u <= n; u++){
	for(int y : v[u])
	    if(h[u]+1 == h[y])
		g[y].PB(u);
    }
    
    int mn = 0, mx = 0;
    for(int i = 0; i < k-1; i++){
	if(h[a[i]]+1 != h[a[i+1]])
	    mn++, mx++;
	else if(is[a[i+1]])
	    mx++;
    }
    return cout << mn << " " << mx << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")