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
#define INF 1000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
ll n, k;
ll a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> a >> b;
    ll dist1 = (b-a+k)%k;
    ll dist2 = (k*2-b-a)%k;
    /*ll gcd1 = __gcd(dist1, k);
    ll gcd2 = __gcd(dist2, k);
    ll lcm1 = dist1*k/gcd1;
    ll lcm2 = dist2*k/gcd2;

    ll mx = n*k/min(gcd1, gcd2);
    ll mn = n*k/max(lcm1, lcm2);*/
    ll mn = INF, mx = 0;
    F0R(i, n){
        ll res1 = dist1+i*k;
        if(res1 != 0){
            ll amt1 = n*k/(__gcd(res1, n*k));
            mn = min(mn, amt1);
            mx = max(mx, amt1);
        } else{
            mn = 1;
            mx = max(mx, n);
        }

        ll res2 = dist2+i*k;
        if(res2 != 0){
            ll amt2 = n*k/(__gcd(res2, n*k));
            mn = min(mn, amt2);
            mx = max(mx, amt2);
        } else{
            mn = 1;
            mx = max(mx, n);
        }
    }

    cout << mn << " " << mx << "\n";
    
    return 0;
}