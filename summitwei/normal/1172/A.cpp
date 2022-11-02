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
int n;
int a[MN], b[MN];
int unt[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        unt[a[i]] = 0;
    }
    int mx = 0;
    F0R(i, n){
        cin >> b[i];
        if(b[i] == 0) continue;
        unt[b[i]] = i-b[i]+2;
        //cout << i << " " << unt[b[i]] << "\n";
        mx = max(mx, unt[b[i]]);
    }

    F0R(i, n){
        if(b[i] == 1){
            bool ok = true;
            FOR(j, i+1, n-1){
                if(b[j] != b[j-1]+1){
                    ok = false;
                    break;
                }
            }
            F0R(j, i){
                if(b[j] == 0) continue;
                int stp = n-i;
                if(unt[b[j]] > -stp){
                    ok = false;
                    break;
                }
            }

            if(ok){
                cout << i << "\n";
                return 0;
            }
            break;
        }
    }

    cout << mx+n;
    return 0;
}