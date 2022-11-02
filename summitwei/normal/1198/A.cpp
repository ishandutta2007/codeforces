#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 400005
int n; ll sz;
ll a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;

    cin >> n >> sz;
    ll numb = sz*8/n;
    ll tot = 1LL<<(min(40LL, numb));
    F0R(i, n){
        cin >> a[i];
    }
    sort(a, a+n);
    ll cur = 1;
    ll r = 0;
    F0R(i, n){
        if(i != 0 && a[i] != a[i-1]) --cur;
        //cout << a[i] << " ";
        while(r < n && cur <= tot){
            ++r;
            if(a[r] != a[r-1]) ++cur;
        }
        //cout << "r is " << r << "\n";
        ans = max(ans, r-i);
    }

    cout << n-ans << "\n";

    return 0;
}