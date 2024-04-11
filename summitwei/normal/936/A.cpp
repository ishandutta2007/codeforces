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
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
ll k, d, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> d >> t;
    ll tim;
    if(k <= d){
        tim = d;
    } else{
        tim = ((k+d-1)/d)*d;
    }
    ll one = tim+k;
    ll ree = 2*t/one;
    ll ree2 = 2*t-ree*one;
    cout << fixed << setprecision(10);
    if(ree2 > 2*k){
        cout << tim*ree+ree2-k << "\n";
    } else{
        cout << tim*ree+ree2/2.0 << "\n";
    }
    
    return 0;
}