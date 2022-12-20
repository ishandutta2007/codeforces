#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 1e5 + 10, lg = 20;

ll X[maxn], Y[maxn];
int f[maxn];

int sp[lg][maxn];
int h[maxn];
vector<int> v[maxn];

void dfs(int u){
    for(int y : v[u]){
	h[y] = h[u] + 1;
	dfs(y);
    }	
}
int lca(int a, int b){
    if(h[a] < h[b])
	swap(a, b);
    for(int i = lg-1; i >= 0; i--)
	if(h[sp[i][a]] >= h[b])
	    a = sp[i][a];
    if(a == b)
	return a;
    for(int i = lg-1; i >= 0; i--)
	if(sp[i][a] != sp[i][b])
	    a = sp[i][a], b = sp[i][b];
    return sp[0][a];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> X[i] >> Y[i]; 
    }
    vector<int> vec;
    for(int i = n-1; i >= 0; i--){
	while(sz(vec) > 1){
	    int _A = vec[sz(vec)-1], _B = vec[sz(vec)-2], _C = i;
	    pll A = {X[_A], Y[_A]}, B = {X[_B], Y[_B]}, C = {X[_C], Y[_C]};
	    if(1ll * (A.S - B.S) * (B.F - C.F) >= 1ll * (B.S - C.S) * (A.F - B.F))
		break;
	    vec.pop_back();
	}
	if(vec.empty())
	    f[i] = i;
	else
	    f[i] = vec.back();
	vec.PB(i);
    }
    for(int i = 0; i < n; i++){
	sp[0][i] = f[i];
    }
    for(int i = 1; i < lg; i++){
	for(int j = 0; j < n; j++){
	    sp[i][j] = sp[i-1][sp[i-1][j]];
	}
    }
    for(int i = 0; i < n-1; i++){
	v[f[i]].PB(i);
    }
    dfs(n-1);
    int q;
    cin >> q;
    while(q--){
	int a, b;
	cin >> a >> b;
	cout << lca(--a, --b) + 1 << " ";
    }
    return cout << endl, 0;
}