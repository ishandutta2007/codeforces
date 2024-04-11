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
#define MOD 998244353LL
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

    ll a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    /*ll x = __gcd(__gcd(a1, b1), c1), y = __gcd(__gcd(a2, b2), c2);
    a1 /= x; b1 /= x; c1 /= x; a2 /= y; b2 /= y; c2 /= y;
    if(a1 < 0){
        a1 = -a1; b1 = -a1; c1 = -a1;
    }
    if(a2 < 0){
        a2 = -a2; b2 = -b2; c2 = -c2;
    }*/
    if(a1 == b1 && a1 == 0){
        if(c1 == 0){
            if(a2 == b2 && a2 == 0){
                if(c2 == 0){
                    cout << "-1\n";
                    return 0;
                } else{
                    cout << "0\n";
                    return 0;
                }
            } else{
                cout << "-1\n";
                return 0;
            }
        } else{
            cout << "0\n";
            return 0;
        }
    }
    if(a1*b2==b1*a2){
        /*if(a1 == a2 && b1 == b2 && c1 == c2){
            cout << "-1\n";
        } else{
            cout << "0\n";
        }*/
        if(a1*c2==a2*c1 && b1*c2==c1*b2){
            cout << "-1\n";
        } else{
            cout << "0\n";
        }
    } else{
        cout << "1\n";
    }
    //bruh moment
    
    return 0;
}