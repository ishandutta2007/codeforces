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
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 205
int n, m, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    cout << n+m+n*m-3 << "\n";
    F0R(i, n-1) cout << "U";
    F0R(j, m-1) cout << "L";
    F0R(i, n){
        F0R(j, m-1){
            if(i%2 == 0) cout << "R";
            else cout << "L";
        }
        if(i != n-1) cout << "D";
    }

    return 0;
}