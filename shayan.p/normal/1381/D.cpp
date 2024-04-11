// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-21

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

int h[maxn], pr[maxn];
vector<int> v[maxn];
bool mark[maxn];

int far(int u, int par = -1){
    pr[u] = par;
    int ans = u;
    h[u] = (par == -1 ? 0 : (h[par] + 1));
    for(int y : v[u]){
	if(y != par && !mark[y]){
	    int x = far(y, u);
	    if(h[x] > h[ans])
		ans = x;
	}
    }    
    return ans;
}

int sp[20][maxn], bst[maxn];

void prep(int u, int par = 0){
    sp[0][u] = par;
    for(int i = 1; i < 20; i++)
	sp[i][u] = sp[i-1][sp[i-1][u]];
    h[u] = h[par] + 1;
    bst[u] = u;
    for(int y : v[u]){
	if(y != par){
	    prep(y, u);
	    if(h[ bst[u] ] < h[ bst[y] ])
		bst[u] = bst[y];
	}
    }
}
int up(int a, int x){
    for(int i = 0; i < 20; i++)
	if(bit(x, i))
	    a = sp[i][a];
    return a;
}
int lca(int a, int b){
    if(h[a] <= h[b])
	swap(a, b);
    for(int i = 19; i >= 0; i--){
	if(h[ sp[i][a] ] >= h[b])
	    a = sp[i][a];
    }
    if(a == b)
	return a;
    for(int i = 19; i >= 0; i--){
	if(sp[i][a] != sp[i][b])
	    a = sp[i][a], b = sp[i][b];
    }
    return sp[0][a];
}
int dis(int a, int b){
    return h[a] + h[b] - 2 * h[lca(a, b)];
}

bool can(int &a, int &b, int ds, int c){
    far(c);
    if(h[a] - h[b] != ds)
	return 0;
    int w = h[b];
    for(int i = 0; i < w; i++)
	a = pr[a], b = pr[b];
    return 1;
}
bool solve(){
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
	v[i].clear();
	mark[i] = 0;
    }
    for(int i = 0; i < n-1; i++){
	int x, y;
	cin >> x >> y;
	v[x].PB(y);
	v[y].PB(x);
    }
	
    int A = far(1);
    int B = far(A);
    int D = h[B];
    int center = B;
    for(int i = 0; i < (D/2); i++)
	center = pr[center];
    prep(center);
    int deepa = h[a], deepb = h[b], lc = lca(a, b), ds = dis(a, b);
    while(true){
	int can = 0;
	int u = bst[a];
	if(h[u] - h[lc] >= ds){
	    a = u, b = up(a, ds);
	    break;
	}
	can+= deepa < h[u];
	deepa = max(deepa, h[u]);
	b = up(b, h[u] - h[a]);
	a = u;

	u = bst[b];
	if(h[u] - h[lc] >= ds){
	    a = u, b = up(a, ds);
	    break;
	}
	can+= deepb < h[u];
	deepb = max(deepb, h[u]);
	a = up(a, h[u] - h[b]);
	b = u;
	if(can == 0)
	    return 0;
    }
    if( !can(a, b, ds, A) && !can(a, b, ds, B) )
	return 0;
    if( !can(b, a, ds, A) && !can(b, a, ds, B) )
	return 0;
    far(A);
    int tmp = B;
    while(tmp != -1)
	mark[tmp] = 1, tmp = pr[tmp];
    tmp = B;
    while(tmp != -1){
	int nx = pr[tmp];
	if(h[ far(tmp) ] >= ds)
	    return 1;
	tmp = nx;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << (solve() ? "YES\n" : "NO\n");
    }
}