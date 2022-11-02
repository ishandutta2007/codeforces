#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int t;
int n;
string s;
int dp[MN];
string strs[4] = {"RL", "RRL", "RLL", "RRLL"};
int dif(int tp, int l){
    int cnt = 0;
    F0R(i, strs[tp].length()){
        if(strs[tp][i] != s[l+i]) ++cnt;
    }
    //cout << tp << " " << l << " " << cnt << "\n";
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> s;
        F0R(i, 4){
            s.pb(s[i]);
        }
        int mn = INF;
        F0R(st, 4){
            //cout << "take " << st << "\n";
            dp[0] = 0;
            dp[1] = INF;
            FOR(i, 2, n){
                dp[i] = INF;
                if(i>=2){
                    dp[i] = min(dp[i], dp[i-2]+dif(0, i-2+st));
                }
                if(i>=3){
                    dp[i] = min(dp[i], dp[i-3]+dif(1, i-3+st));
                }
                if(i>=3){
                    dp[i] = min(dp[i], dp[i-3]+dif(2, i-3+st));
                }
                if(i>=4){
                    dp[i] = min(dp[i], dp[i-4]+dif(3, i-4+st));
                }
                //cout << i << " " << dp[i] << "\n";
            }
            mn = min(mn, dp[n]);
        }
        cout << mn << "\n";
    }

    return 0;
}