#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
vi ch[MN];
int par[MN];
int val[MN];
int w[MN];

void dfs(int cn, int d){
    if(d == 1){
        w[cn] = val[cn];
    } else if(d % 2 == 0){
        if(ch[cn].size() == 0){
            val[cn] = val[par[cn]];
            w[cn] = 0;

            return;
        }

        int mn = INF;
        F0R(i, ch[cn].size()){
            int nn = ch[cn][i];
            mn = min(mn, val[nn]);
        }

        //w[cn] = mn;

        if(mn < val[par[cn]]){
            cout << "-1\n";
            exit(0);
        }

        int amt = mn - val[par[cn]];
        val[cn] = mn;
        w[cn] = amt;
    } else{
        int pv = val[par[cn]];
        int cur = val[cn];
        int here = cur - pv;
        w[cn] = here;
    }

    F0R(i, ch[cn].size()){
        int nn = ch[cn][i];

        dfs(nn, d+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    FOR(i, 2, n){
        cin >> par[i];
        ch[par[i]].pb(i);
    }
    FOR(i, 1, n){
        cin >> val[i];
    }

    dfs(1, 1);

    ll tot = 0;
    FOR(i, 1, n){
        tot += (ll)w[i];
        //cout << w[i] << " ";
    }

    //cout << "\n";
    cout << tot << "\n";

    return 0;
}