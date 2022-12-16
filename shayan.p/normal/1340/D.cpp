// Never let them see you bleed...
// Shayan.P  2020-04-23

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

vector<int> v[maxn];
vector<pii> ans;

void dfs(int u, int t, int par = -1){
    int cnt = sz(v[u]) - (par != -1);
    ans.PB({u, t});
    int T = t;
    bool done = 0;
    for(int y : v[u]){
	if(y != par){
	    if(!done && T - cnt - 1 >= 0){
		done = 1;
		t = T - cnt - 1;
		ans.PB({u, t});
	    }				
	    dfs(y, ++t, u);
	    ans.PB({u, t});
	    --cnt;
	}
    }
    if(t != T-1){
	if(par != -1)
	    ans.PB({u, T-1});
    }    
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
    dfs(1, 0);
    cout << sz(ans) << "\n";
    for(pii p : ans){
	cout << p.F << " " << p.S << "\n";
    }
    return 0;
}