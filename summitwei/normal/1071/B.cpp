#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n, k;
char gr[MN][MN];
int dp[MN][MN]; //min num of things needed to yield this guy as bst
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, 0x3f, sizeof dp);

    cin >> n >> k;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> gr[i][j];
        }
    }
    if(gr[1][1] != 'a' && k != 0){
        dp[1][1] = 1;
        s += 'a';
    } else{
        s += gr[1][1];
        dp[1][1] = 0;
    }
    FOR(sm, 3, 2*n){
        char mn = 'z';
        FOR(i, 1, n){
            int j = sm-i;
            if(j <= 0 || j > n) continue;
            
            if(i != 1){
                if(dp[i-1][j] < k){
                    mn = 'a';
                } else if(dp[i-1][j] == k){
                    mn = min(mn, gr[i][j]);
                }
            }
            if(j != 1){
                if(dp[i][j-1] < k){
                    mn = 'a';
                } else if(dp[i][j-1] == k){
                    mn = min(mn, gr[i][j]);
                }
            }
        }
        s += mn;
        FOR(i, 1, n){
            int j = sm-i;
            if(j <= 0 || j > n) continue;

            if(i != 1){
                if(gr[i][j] == mn){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                } else{
                    if(dp[i-1][j] < k) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
            }
            if(j != 1){
                if(gr[i][j] == mn){
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                } else{
                    if(dp[i][j-1] < k) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }

    cout << s << "\n";

    return 0;
}