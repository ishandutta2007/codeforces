#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 3e5 + 10;

bool mark[maxn], state[maxn];
int seen = 0;
vector<int> ans, v[maxn];

void dfs(int u){
    mark[u] = 1;
    seen++;
    for(int y : v[u]){
	if(mark[y])
	    state[u]|= state[y];
    }
    state[u]^= 1;
    if(state[u])
	ans.PB(u);
    for(int y : v[u]){
	if(!mark[y])
	    dfs(y);
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
	    mark[i] = 0;
	    state[i] = 0;
	    v[i].clear();
	}
	seen = 0;
	ans.clear();
	while(m--){
	    int a, b;
	    cin >> a >> b;
	    v[a].PB(b);
	    v[b].PB(a);
	}
	dfs(1);
	if(seen != n){
	    cout << "NO\n";
	}
	else{
	    cout << "YES\n";
	    cout << sz(ans) << "\n";
	    for(int x : ans)
		cout << x << " ";
	    cout << "\n";
	}
    }
}