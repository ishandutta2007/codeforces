#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
int lfc;
int nv[MN];
int par[MN];
vi ch[MN];

int dfs(int cn){ //amt of biggers if this is >= desired
    if(ch[cn].size() == 0){
        return 1;
    }

    int ans = nv[cn] ? INF : 0; //sum if 0, min = 1
    F0R(i, ch[cn].size()){
        int nn = ch[cn][i];

        int res = dfs(nn);
        if(nv[cn] == 0){
            ans += res;
        } else{
            ans = min(ans, res);
        }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> nv[i];
    }
    FOR(i, 2, n){
        cin >> par[i];
        ch[par[i]].pb(i);
    }
    FOR(i, 1, n){
        if(ch[i].size() == 0){
            lfc++;
        }
    }

    int res = dfs(1);
    int ans = lfc-res+1;

    cout << ans << "\n";
    
    return 0;
}