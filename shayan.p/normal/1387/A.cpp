
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

vector<pii> v[maxn];
int mark[maxn];
pii p[maxn];
double ans[maxn];
vector<int> vec;
set<int> vals;

void dfs(int u){
    vec.PB(p[u].S * p[u].F);
    
    mark[u] = 1;
    for(pii pp : v[u]){
	int y = pp.F, c = pp.S;
	if(mark[y]){
	    if(p[y].F + p[u].F == 0){
		if(p[y].S + p[u].S != c)
		    cout << "NO\n", exit(0);		
	    }
	    else{
		vals.insert( (c - p[u].S - p[y].S) * p[u].F );
		if(sz(vals) > 1)
		    cout << "NO\n", exit(0);
	    }
	}
	else{
	    p[y] = {-p[u].F, c - p[u].S};
	    dfs(y);
	}
    }
}
void dfs2(int u, double num){
    mark[u] = 2;
    ans[u] = p[u].F * num + p[u].S;
    for(pii pp : v[u]){
	if(mark[pp.F] != 2)
	    dfs2(pp.F, num);
    }
}

void solve(int u){
    p[u] = {1, 0};
    vec.clear();
    vals.clear();
    dfs(u);
    double num;
    if(vals.empty()){
	sort(vec.begin(), vec.end());
	num = -vec[ sz(vec) / 2 ];
    }
    else{
	num = double(*vals.begin()) / 2;
    }
    dfs2(u, num);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	v[a].PB({b, c});
	v[b].PB({a, c});
    }
    for(int i = 1; i <= n; i++){
	if(!mark[i])
	    solve(i);
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}