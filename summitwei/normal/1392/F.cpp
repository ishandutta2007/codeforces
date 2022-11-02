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

#define MN 1000005
ll n;
ll h[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll sm=0;
    F0R(i, n){
        cin >> h[i];
        sm += h[i];
    }
    sm -= (n*(n-3)/2+1);
    ll a = sm/n, k=sm%n;
    F0R(i, n){
        if(i<=k) cout << a+i;
        else cout << a+i-1;
        cout << " ";
    }
    cout << "\n";

    return 0;
}