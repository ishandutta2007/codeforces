#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int n;
int arr[MN];
ll pri[MN];
bool isCons[MN][MN];

int ps[MN][2];

ll dp2[MN][MN];
ll dp[MN][MN][MN];

ll best(int l, int r);
ll getDP(int l, int r, int k){ //k = length of final substring
    /*if(r < l) return 0;*/
    if(r-l+1 < k){
        dp[l][r][k] = -INF;
        return -INF;
    }
    if(r < l) return -INF;
    if(dp[l][r][k] != 0){
        //cout << "dp " << l << " " << r << " " << k << " is already called and is " << dp[l][r][k] << "\n";
        return dp[l][r][k];
    }

    if(k == r-l+1){
        //if(isCons[l][r]) ans = pri[r-l];
        //else ans = -INF;
        //dp[l][r][k] = ans;
        //return ans;
        if(isCons[l][r]) return 0;
        else{
            //cout << l << " " << r << " not all same\n";
            dp[l][r][k] = -INF;
            return -INF;
        }
    }
    if(l == r){
        return -INF; //bad since k != 1
    }
    if(k == 1){
        dp[l][r][k] = best(l+1, r);
        return dp[l][r][k];
    }

    ll mx = -INF;
    FOR(i, l+1, r){
        if(arr[l] != arr[i]) continue;
        //mx = max(mx, best(l+1, i-1) + getDP(i+1, r, k-1));
        if(i == l+1){
            //cout << l << " " << r << " " << k << " " << i << "\n";
            mx = max(mx, getDP(i, r, k-1));
            //cout << mx << "\n";
        } else if(i == r){
            //mx = max(mx, best(l+1, r-1));
            if(k == 2){
                mx = max(mx, best(l+1, i-1));
            }
        } else{
            mx = max(mx, best(l+1, i-1) + getDP(i, r, k-1));
        }
    }

    //cout << "best for " << l << " " << r << " " << k << " is " << mx << "\n";

    dp[l][r][k] = mx;
    return mx;
}
ll best(int l, int r){
    if(r < l) return -INF;
    if(dp2[l][r] != 0) return dp2[l][r];

    if(l == r){
        dp2[l][r] = pri[0];
        return pri[0];
    }

    ll mx = 0;
    FOR(k, 1, r-l+1){
        ll x = getDP(l, r, k) +pri[k-1];
        //cout << "val at " << k << " for " << l << " " << r << " " << x << "\n";
        mx = max(mx, x);
    }

    //cout << "best for " << l << " " << r << " is " << mx << "\n";
    dp2[l][r] = mx;
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("cfout.out", "w", stdout);

    cin >> n;
    F0R(i, n){
        char c;
        cin >> c;
        arr[i] = c-'0';
        if(i == 0){
            ps[i][c-'0'] = 1;
            ps[i]['1'-c] = 0;
        }
    }
    F0R(i, n){
        cin >> pri[i];
    }
    
    F0R(i, n){
        FOR(j, i, n-1){
            int works = true;
            FOR(k, i+1, j){
                if(arr[k] != arr[k-1]){
                    works = false;
                    break;
                }
            }

            if(works){
                isCons[i][j] = true;
            }
        }
    }

    cout << best(0, n-1) << "\n";

    return 0;
}