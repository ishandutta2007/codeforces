#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 1000000000LL
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
int n, k;
int p[MN];
int loc[MN];
ll sm;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    int t=0;
    FOR(i, 1, n){
        cin >> p[i];
        if(n-p[i] < k){
            loc[t++] = i;
            sm += p[i];
        }
    }
    ll amt = 1;
    F0R(i, k-1){
        amt *= loc[i+1]-loc[i];
        amt %= MOD;
    }
    cout << sm << " " << amt << "\n";

    return 0;
}