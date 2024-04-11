#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
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

#define MN 105
int t;
int r, c;
int k;
char gr[MN][MN];
int od[MN*MN];
char ntoc[MN];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    F0R(i, 26){
        ntoc[i] = 'A'+i;
        ntoc[26+i] = 'a'+i;
    }
    F0R(i, 10){
        ntoc[52+i] = '0'+i;
    }

    cin >> t;
    F0R(_, t){
        cin >> r >> c >> k;
        vi ri;
        F0R(i, r){
            F0R(j, c){
                cin >> gr[i][j];
                if(gr[i][j] == 'R'){
                    int loc = i*c+(i%2?j:(c-1-j));
                    //cout << loc << "\n";
                    ri.pb(loc);
                }
            }
        }
        int amt = ri.size()/k;
        int res = ri.size()%k;
        int cur = 0;
        int cnt = 0;
        int tot = 0;
        //cout << amt << " " << res << "\n";
        sort(ri.begin(), ri.end());
        F0R(i, k){
            //cout << "on " << i << "\n";
            while(true){
                //cout << "doing " << cur << "\n";
                od[cur] = i;
                if(ri[cnt] == cur){
                    ++tot;
                    ++cnt;
                }
                ++cur;
                if((i >= res && tot == amt) || (i<res && tot==amt+1)){
                    tot = 0;
                    break;
                }
            }
            if(i == k-1){
                FOR(j, cur, r*c-1){
                    od[j] = i;
                }
            }
        }
        F0R(i, r){
            F0R(j, c){
                int loc = i*c+(i%2?j:(c-1-j));
                cout << ntoc[od[loc]];
            }
            cout << "\n";
        }
    }
    
    return 0;
}