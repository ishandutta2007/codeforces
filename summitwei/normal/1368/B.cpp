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

#define MN 100005
ll amt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> amt;
    FOR(i, 1, 50){
        FOR(j, 0, 10){
            ll prod = 1;
            FOR(k, 1, j) prod *= (i+1);
            FOR(k, j+1, 10) prod *= i;
            if(prod >= amt){
                string s = "codeforces";
                F0R(k, j){
                    F0R(_, i+1) cout << s[k];
                }
                FOR(k, j, 9){
                    F0R(_, i) cout << s[k];
                }
                return 0;
            }
        }
    }

    return 0;
}