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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << 1996 << "\n";
    FOR(i, 2, 999){
        cout << i << " 1\n";
        cout << i << " 2\n";
    }
    RFOR(i, 999, 2){
        cout << i << " 1\n";
        cout << i << " 2\n";
    }

    return 0;
}