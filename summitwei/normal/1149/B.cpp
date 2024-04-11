#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
#define MM 255
int n, q;
string s;
string a[3];
int szs[3];
int dp[MM][MM][MM];
int cur[26];
int nxt[MN][26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> s;
    F0R(i, 26) cur[i] = nxt[n+1][i] = n+1;
    RFOR(i, n, 1){
        F0R(j, 26) nxt[i][j] = cur[j];
        cur[s[i-1]-'a'] = i;
    }
    F0R(j, 26) nxt[0][j] = cur[j];
    /*F0R(i, n+1){
        F0R(j, 26){
            cout << nxt[i][j] << " ";
        }
        cout << "\n";
    }*/
    
    dp[0][0][0] = 0;

    F0R(_, q){
        char c;
        cin >> c;
        if(c == '+'){
            int ind; char x;
            cin >> ind >> x;
            a[ind-1].push_back(x);
            ++szs[ind-1];

            if(ind == 1){ //calc dp[szs[1]][]
                int loc = szs[0];
                FOR(i, 0, szs[1]){
                    FOR(j, 0, szs[2]){
                        dp[loc][i][j] = nxt[dp[loc-1][i][j]][x-'a'];

                        if(i != 0){
                            dp[loc][i][j] = min(dp[loc][i][j], nxt[dp[loc][i-1][j]][a[1][i-1]-'a']);
                        }
                        if(j != 0){
                            dp[loc][i][j] = min(dp[loc][i][j], nxt[dp[loc][i][j-1]][a[2][j-1]-'a']);
                        }

                        //cout << dp[loc][i][j] << " ";
                    }
                    //cout << "\n";
                }
            } else if(ind == 2){
                int loc = szs[1];
                FOR(i, 0, szs[0]){
                    FOR(j, 0, szs[2]){
                        dp[i][loc][j] = nxt[dp[i][loc-1][j]][x-'a'];

                        if(i != 0){
                            dp[i][loc][j] = min(dp[i][loc][j], nxt[dp[i-1][loc][j]][a[0][i-1]-'a']);
                        }
                        if(j != 0){
                            dp[i][loc][j] = min(dp[i][loc][j], nxt[dp[i][loc][j-1]][a[2][j-1]-'a']);
                        }

                        //cout << dp[i][loc][j] << " ";
                    }
                    //cout << "\n";
                }
            } else{
                int loc = szs[2];
                FOR(i, 0, szs[0]){
                    FOR(j, 0, szs[1]){
                        //int nx1 = x-'a', nx2 = a[0][szs[0]-1]-'a', nx3 = a[1][szs[1]-1]-'a';
                        dp[i][j][loc] = nxt[dp[i][j][loc-1]][x-'a'];
                        //cout << "hmm " << i << " " << j << " " << dp[i][j][loc] << "\n";
                        //cout << nx1 << " " << nx2 << " " << nx3 << "\n";

                        if(i != 0){
                            dp[i][j][loc] = min(dp[i][j][loc], nxt[dp[i-1][j][loc]][a[0][i-1]-'a']);
                            //cout << "hmm " << i << " " << j << " " << dp[i][j][loc] << "\n";
                        }
                        if(j != 0){
                            dp[i][j][loc] = min(dp[i][j][loc], nxt[dp[i][j-1][loc]][a[1][j-1]-'a']);
                            //cout << "hmm " << i << " " << j << " " << dp[i][j][loc] << "\n";
                        }

                        //cout << dp[i][j][loc] << " ";
                    }
                    //cout << "\n";
                }
            }
        } else{
            int i;
            cin >> i;
            a[i-1].pop_back();
            --szs[i-1];
        }

        /*FOR(i, 0, szs[0]){
            FOR(j, 0, szs[1]){
                FOR(k, 0, szs[2]){
                    cout << dp[i][j][k] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        F0R(i, 3) cout << a[i] << " ";
        cout << "\n";*/

        //cout << dp[szs[0]][szs[1]][szs[2]] << " ";
        if(dp[szs[0]][szs[1]][szs[2]] <= n){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    
    return 0;
}