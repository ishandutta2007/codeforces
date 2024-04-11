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

vector<int> v[maxn];
int SZ[maxn];
void dfsSZ(int u, int par = -1){
    SZ[u] = 1;
    for(int y : v[u])
	if(y != par)
	    dfsSZ(y, u), SZ[u]+= SZ[y];		
}
int center(int u, int N, int par = -1){
    for(int y : v[u])
	if(y != par && SZ[y] > N)
	    return center(y, N, u);
    return u;
}

ll ANS;
int ans[maxn];
vector<int> vec;

void dfs(int u, int par = -1){
    vec.PB(u);
    for(int y : v[u])
	if(y != par)
	    ANS+= 2 * SZ[y], dfs(y, u);
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
    dfsSZ(1);
    int r = center(1, n/2);
    dfsSZ(r);
    dfs(r);
    for(int i = 0; i < n; i++){
	ans[ vec[i] ] = vec[(i + (n/2)) % n];
    }
    cout << ANS << "\n";
    for(int i = 1; i <= n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}