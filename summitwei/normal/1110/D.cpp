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

#define MN 1000005
int n, m;
int cnt[MN];
int dp[MN][3][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -0x3f, sizeof dp);

    cin >> n >> m;
    F0R(_, n){
        int x;
        cin >> x;
        cnt[x]++;
    }

    dp[1][0][0] = 0;

    FOR(i, 1, m){
        F0R(j, 3){
            F0R(k, 3){
                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
                F0R(l, 3){
                    if(j + k + l > cnt[i]) continue;
                    int extra = (cnt[i]-j-k-l)/3;
                    //cout << "for " << l << ", val is " << dp[i][j][k]+extra+j << "\n";
                    dp[i+1][k][l] = max(dp[i+1][k][l], dp[i][j][k]+extra+j);
                }
            }
        }
    }

    cout << dp[m+1][0][0] << "\n";

    return 0;
}