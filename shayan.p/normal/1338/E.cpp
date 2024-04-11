// Never let them see you bleed...
// Shayan.P  2020-04-15

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 8010, mod = 1e9 + 7, inf = 1e9 + 10;

bool adj[maxn][maxn];
int dg[maxn], arr[maxn];
ll ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	for(int j = 0; j < (n/4); j++){
	    char ch;
	    cin >> ch;
	    int num = ('0' <= ch && ch <= '9') ? (ch - '0') : (10 + ch - 'A');
	    for(int k = 0; k < 4; k++)
		adj[i][4*j + 3-k] = bit(num, k);
	}
    }
    memset(dg, 0, sizeof dg);
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++)
	    dg[i]+= adj[i][j];
    }
    iota(arr, arr+n, 0);
    sort(arr, arr+n, [&](int i, int j){ return dg[i] < dg[j]; } );
    int C = n;
    while(C > 1 && dg[arr[C-1]] == C-1){
	ans+= 1ll * (C-1) * (614 * n + 1);
	--C;
    }
    if(C == 1)
	return cout << ans << endl, 0;
    
    vector<int> v1, v2, c1, c2;
    v1.PB(arr[0]);
    for(int i = 1; i < C; i++){
	if(adj[ arr[i] ][ arr[0] ])
	    v1.PB(arr[i]);
	else
	    v2.PB(arr[i]);
    }
    ans+= 1ll * C * (C-1) / 2 * 3;

    memset(dg, 0, sizeof dg);
    for(int x : v1){
	for(int y : v2){
	    dg[x]+= adj[x][y];
	    dg[y]+= adj[y][x];
	}
    }
    for(int x : v1){
	c1.PB(dg[x]);
    }
    for(int x : v2){
	c2.PB(dg[x]);
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());    
    for(int i = 0; i < sz(c1); i++){
	if(c1[i] == 0)
	    ans+= i;
	else
	    ans+= i - c2[ c1[i]-1 ];
    }
    for(int i = 0; i < sz(c2); i++){
	if(c2[i] == 0)
	    ans+= i;
	else
	    ans+= i - c1[ c2[i]-1 ];
    }
    return cout << ans << endl, 0;
}