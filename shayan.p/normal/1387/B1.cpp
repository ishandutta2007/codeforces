// hello darkness my old friend, I've come to talk with you again

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

vector<int> v[maxn], g[maxn];
bool mark[maxn];
int ans[maxn], ANS;

bool dfs(int u, int par = -1){
    bool ok = 0;
    for(int y : v[u]){
	if(y != par && !dfs(y, u)){
	    ok = 1;
	    g[u].PB(y);
	    g[y].PB(u);
	    ANS+= 2;
	}
    }
    if(!ok && par == -1){
	int y = v[u].back();
	g[u].PB(y);
	g[y].PB(u);
	ANS+= 2;
    }
    return ok;
}

int tmp;

void solve(int u){
    mark[u] = 1;
    if(tmp != -1)
	ans[tmp] = u;
    tmp = u;
    for(int y : g[u])
	if(!mark[y])
	    solve(y);
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
    dfs(1);
    for(int i = 1; i <= n; i++){
	if(!mark[i])
	    tmp = -1, solve(i), ans[tmp] = i;
    }
    cout << ANS << "\n";
    for(int i = 1; i <= n; i++)
	cout << ans[i] << " ";
    return cout << endl, 0;
}