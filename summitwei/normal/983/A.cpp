#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
ll p, q, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(_, n){
        cin >> p >> q >> b;
        ll gcd = __gcd(p, q);
        q /= gcd;
        //q %= b;
        ll cg = __gcd(q, b);
        while(cg != 1){
            while(q % cg == 0)
                q /= cg;
            cg = __gcd(q, b);
        }
        if(q == 1){
            cout << "Finite\n";
        } else{
            cout << "Infinite\n";
        }
    }

    return 0;
}