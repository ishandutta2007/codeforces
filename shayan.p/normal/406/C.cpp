#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

vector<int> v[maxn];
vector< pair<pii, int> > ans;
int mark[maxn];

bool dfs(int u, int par){
    mark[u] = 1;
    vector<int> vec;
    for(auto y : v[u]){
	if(y == par)
	    continue;
	if(mark[y] == 1)
	    vec.PB(y);
	if(mark[y] == 0)
	    if(dfs(y, u))
		vec.PB(y);
    }
    mark[u] = 2;
    while(sz(vec) > 1){
	int A = vec.back();
	vec.pop_back();
	int B = vec.back();
	vec.pop_back();
	ans.PB({{A, u}, B});	
    }
    if(sz(vec) == 1){
	ans.PB({{par, u}, vec.back()});
	return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);	
    }
    if(m & 1)
	return cout << "No solution\n", 0;
    dfs(1, -1);
    for(auto x : ans)
	cout << x.F.F << " " << x.F.S << " " << x.S << "\n";
    return 0;
}