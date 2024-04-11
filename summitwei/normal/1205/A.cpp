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
#define INF 1000000000000000LL
#define MOD 998244353
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
int ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n % 2 == 0){
        cout << "NO\n";
        return 0;
    }
    FOR(i, 1, n){
        if(i % 2 == 1){
            ans[i] = 2*i-1;
            ans[i+n] = 2*i;
        } else{
            ans[i] = 2*i;
            ans[i+n] = 2*i-1;
        }
    }
    cout << "YES\n";
    FOR(i, 1, 2*n){
        cout << ans[i] << " ";
    }

    return 0;
}