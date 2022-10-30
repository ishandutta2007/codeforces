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
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int cand[MN];
ll u, v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> u >> v;
    if(u > v || (v-u)%2 != 0){
        cout << "-1\n";
        return 0;
    }

    if(u == 0 && v == 0){
        cout << "0\n";
        return 0;
    }
    if(u == v){
        cout << "1\n" << u << "\n";
        return 0;
    }
    
    ll a = 0, b = 0;

    bool ok = true;
    ll dif = v-u;
    FOR(i, 1, 61){
        if(dif & (1LL<<i)){
            if(u & (1LL<<(i-1))){
                ok = false;
                break;
            } else{
                a += (1LL<<(i-1));
                b += (1LL<<(i-1));
            }
        } else{
            if(u & (1LL<<(i-1))){
                a += (1LL<<(i-1));
            }
        }
    }
    if(ok){
        cout << "2\n" << a << " " << b << "\n";
    } else{
        cout << "3\n" << dif/2 << " " << dif/2 << " " << u << "\n";
    }

    return 0;
}