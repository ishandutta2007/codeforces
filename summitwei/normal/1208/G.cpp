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
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n, k;
int phi[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << "3\n";
        return 0;
    }
    iota(phi, phi+n+1, 0);
    FOR(i, 2, n){
        if(phi[i] == i){
            --phi[i];
            for(int j=2*i; j<=n; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    sort(phi+3, phi+n+1);
    ll sm = accumulate(phi+3, phi+k+3, 0LL);

    cout << sm+2 << "\n";

    return 0;
}