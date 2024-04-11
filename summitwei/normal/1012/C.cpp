#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n;
ll a[MN];
ll dp[MN][MN];
ll ramt[MN], lamt[MN];
ll bhue[MN]; //dif of three or more

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        if(i != 1){
            if(a[i-1] >= a[i]){
                lamt[i] = a[i-1]-a[i]+1;
            }
        }
        if(i != n){
            if(a[i+1] >= a[i]){
                ramt[i] = a[i+1]-a[i]+1;
            }
        }
    }
    memset(bhue, 0x3f, sizeof bhue);
    bhue[0] = 0;
    FOR(i, 1, n){
        FOR(j, 1, n){
            ll bst = bhue[j-1]+lamt[i];
            if(j != 1 && i >= 3){
                ll fix = max(0LL, a[i-1]-min(a[i-2], a[i])+1);
                bst = min(bst, dp[i-2][j-1]+fix);
            }
            dp[i][j] = bst;
        }
        if(i >= 3){
            FOR(j, 1, n){
                bhue[j] = min(bhue[j], dp[i-2][j]+ramt[i-2]);
            }
        }
    }
    FOR(j, 1, (n+1)/2){
        ll ans = INF;
        FOR(i, 1, n){
            ans = min(ans, dp[i][j]+ramt[i]);
        }
        cout << ans << " ";
    }

    return 0;
}