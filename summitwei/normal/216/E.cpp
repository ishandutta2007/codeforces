#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
ll k, b;
ll s[MN];
ll ps[MN];
map<ll, ll> app;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> b >> n;
    ll ans = 0;
    app[0]++;
    ll zs = 0;
    ll zamt = 0;
    FOR(i, 1, n){
        cin >> s[i];
        ps[i] = (ps[i-1]+s[i])%(k-1);
        ans += app[(ps[i]-b+k-1)%(k-1)];
        app[ps[i]]++;
        if(s[i] == 0){
            ++zs;
            zamt += zs;
        } else{
            zs = 0;
        }
    }
    if(b == 0){
        cout << zamt << "\n";
    } else if(b == k-1){
        cout << ans-zamt << "\n";
    } else{
        cout << ans << "\n";
    }

    return 0;
}