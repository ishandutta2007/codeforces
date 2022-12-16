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

const int maxn = 2e4 + 10, inf =1e9 + 10;
const ll infL = 1e18;

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

int tp[maxn], nx[maxn], w[maxn], to[maxn], fr[maxn], C;
ll dis[maxn];
bool mark[maxn];
int Mid;

void digi(int s){
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    fill(dis, dis + maxn, infL);
    memset(mark, 0, sizeof mark);
    
    dis[s] = 0;
    pq.push({0, s});
    
    while(sz(pq)){
	int u = pq.top().S;
	pq.pop();
	if(mark[u])
	    continue;
	mark[u] = 1;
	for(int id = tp[u]; id != -1; id = nx[id]){
	    if(dis[ to[id] ] > dis[u] + (w[id] == 0 ? Mid : w[id]))
		dis[ to[id] ] = dis[u] + (w[id] == 0 ? Mid : w[id]), pq.push({dis[to[id]], to[id]});
	}
    }
}
void dfs(int u){
    mark[u] = 1;
    for(int id = tp[u]; id != -1; id = nx[id])
	if(mark[to[id]] == 0 && dis[ to[id] ] - dis[u] == w[id])
	    dfs(to[id]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    memset(tp, -1, sizeof tp);
    
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;	
	nx[C] = tp[a], tp[a] = C, w[C] = c, to[C] = b, fr[C] = a;
	C++;
	nx[C] = tp[b], tp[b] = C, w[C] = c, to[C] = a, fr[C] = b;
	C++;
    }
    auto print = [&](){
		     cout << "YES\n";
		     for(int i = 0; i < m; i++)
			 cout << fr[2*i] << " " << to[2*i] << " " << w[2*i] << "\n";
		 };
    int l = 0, r = inf;
    while(r-l > 1){
	Mid = (l+r) >> 1;
	digi(s);
	if(dis[t] == L){
	    for(int i = 0; i < m; i++){
		if(w[2*i] == 0)
		    w[2*i] = w[2*i+1] = Mid;
	    }
	    print();
	    return 0;
	}
	if(dis[t] < L)
	    l = Mid;
	else
	    r = Mid;
    }
    if(l == 0 || r == inf)
	return cout << "NO" << endl, 0;
    vector<int> todo;
    for(int i = 0; i < m; i++){
	if(w[2*i] == 0)
	    todo.PB(i), w[2*i] = w[2*i+1] = l;
    }
    Mid = l;
    digi(s);
    while(sz(todo)){
	int id = todo.back();
	todo.pop_back();
	w[2*id]++, w[2*id + 1]++;
	memset(mark, 0, sizeof mark);
	dfs(s);
	for(int i = 0; i < n; i++)
	    if(mark[i] == 0)
		dis[i]++;
	if(dis[t] == L)
	    break;
    }
    print();
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")