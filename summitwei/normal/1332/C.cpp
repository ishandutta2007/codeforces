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
int t;
int n, k;
string s;
int app[MN][26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> k >> s;
        F0R(i, n){
            int re = min(i%k, k-1-(i%k));
            //cout << re << " ";
            app[re][s[i]-'a']++;
        }
        //cout << "\n";
        int amt = 0;
        F0R(i, k){
            int tot=0, mx=0;
            F0R(j, 26){
                mx = max(mx, app[i][j]);
                tot = tot + app[i][j];
            }
            amt += (tot-mx);
        }
        cout << amt << "\n";
        F0R(i, k){
            F0R(j, 26){
                app[i][j] = 0;
            }
        }
    }
    
    return 0;
}