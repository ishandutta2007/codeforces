#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
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
string vals[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[MN];
int dis[MN][10]; //INF if bad
bool dp[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> s[i];
    FOR(i, 1, n){
        F0R(j, 10){
            int cnt = 0;
            F0R(k, 7){
                if(vals[j][k] == '1' && s[i][k] == '0') ++cnt;
                else if(vals[j][k] == '0' && s[i][k] == '1'){cnt = -1; break;}
            }
            dis[i][j] = cnt;
        }
    }
    /*FOR(i, 1, n){
        F0R(j, 10){
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }*/
    dp[n+1][0] = true;
    RFOR(i, n, 1){
        FOR(j, 0, k){
            F0R(m, 10){
                if(dis[i][m] == -1 || dis[i][m] > j) continue;
                dp[i][j] |= dp[i+1][j-dis[i][m]];
            }
        }
    }
    /*FOR(i, 1, n){
        FOR(j, 0, k){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    if(!dp[1][k]){
        cout << "-1\n";
        return 0;
    }

    int cur = k;
    FOR(i, 1, n){
        RFOR(j, 9, 0){
            if(dis[i][j] == -1 || dis[i][j] > cur) continue;
            if(dp[i+1][cur-dis[i][j]]){
                cout << j;
                cur -= dis[i][j];
                break;
            }
        }
    }
    
    return 0;
}