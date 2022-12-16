// hello darkness my old friend, I've come to talk with you again
// Shayan.P  2020-07-24

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

set<int> v[20];
bool mark[20];
vector<int> vec;
int out[20], in[20];
int dp[1<<20], MSK[1<<20];

void dfs(int u){
    vec.PB(u);
    mark[u] = 1;
    for(int y : v[u])
	if(!mark[y])
	    dfs(y);		       
}

void solve(){
    memset(mark, 0, sizeof mark);
    memset(out, 0, sizeof out);
    memset(in, 0, sizeof in);    
    for(int i = 0; i < 20; i++)
	v[i].clear();
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < n; i++){
	int A = a[i] - 'a', B = b[i] - 'a';
	v[A].insert(B);
	v[B].insert(A);
	out[A]|= 1<<B;
	in[B]|= 1<<A;
    }
    int ans = 0;
    for(int u = 0; u < 20; u++){
	if(!mark[u]){
	    vec.clear();
	    dfs(u);
	    for(int msk = 1; msk < (1<<sz(vec)); msk++){
		int I = __builtin_ctz(msk);
		MSK[msk] = MSK[msk ^ (1<<I)] | (1<<vec[I]);
		if(__builtin_popcount(msk) <= 1){
		    dp[msk] = 0;
		    continue;
		}
		dp[msk] = inf;		
		for(int i = 0; i < sz(vec); i++){
		    if(bit(msk, i)){
			dp[msk] = min(dp[msk], 1 + dp[msk ^ (1<<i)] + ((in[vec[i]] & MSK[msk ^ (1<<i)]) ? 1 : 0) );
		    }
		}
	    }
	    ans+= dp[(1<<sz(vec))-1];
	}
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	solve();
    }
}