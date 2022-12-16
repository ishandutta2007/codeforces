// Never let them see you bleed...
// Shayan.P  2020-06-30

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];
vector<int> v[maxn], ans;
vector<int> vid[maxn];

bool is[maxn];

set<pii> st;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
	cin >> a[i];	
    }
    for(int i = 0; i < m; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
	vid[a].PB(i);
	vid[b].PB(i);
    }
    for(int i = 1; i <= n; i++){
	a[i] = sz(v[i]) - a[i];
	st.insert({a[i], i});
    }
    for(int i = 0; i < n; i++){
	int u = st.begin()->S;
	is[u] = 1;
	if(a[u] > 0)
	    return cout << "DEAD\n", 0;
	st.erase({a[u], u});
	for(int y : v[u]){
	    if(!is[y])
		st.erase({a[y], y});	    
	}
	for(int y : v[u]){
	    if(!is[y])
		--a[y];
	}
	for(int y : v[u]){
	    if(!is[y])
		st.insert({a[y], y});
	}
	for(int j = 0; j < sz(v[u]); j++){
	    if(!is[v[u][j]])
		ans.PB(vid[u][j]);
	}
    }
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for(int x : ans){
	cout << ++x << " ";
    }
    return cout << endl, 0;
}