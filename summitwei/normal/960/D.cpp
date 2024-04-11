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
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 70
int q;
ll amt[MN]; //offset of all things
ll sz[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sz[0] = 1;
    FOR(i, 1, 61){
        sz[i] = sz[i-1]*2;
    }
    /*F0R(i, 6) cout << sz[i] << " ";
    cout << "\n";*/

    cin >> q;
    F0R(_, q){
        int c;
        cin >> c;
        if(c == 1){
            ll x, k;
            cin >> x >> k;
            ll lv = (ll)log2(x);
            k = (k%sz[lv]+sz[lv])%sz[lv];
            amt[lv] = (amt[lv]+k)%sz[lv];
        } else if(c == 2){
            ll x, k;
            cin >> x >> k;
            ll lv = (ll)log2(x);
            k = (k%sz[lv]+sz[lv])%sz[lv];
            amt[lv] = (amt[lv]+k)%sz[lv];
            ll ch = k;
            FOR(i, lv+1, 61){
                ch *= 2;
                amt[i] = (amt[i]+ch+sz[i])%sz[i];
            }
        } else{
            ll x;
            cin >> x;
            ll lv = (ll)log2(x);
            RFOR(i, lv, 1){
                cout << x << " ";
                ll nxt = (x+amt[i])%sz[i]+sz[i];
                ll cur = (nxt/2+sz[i-1]-amt[i-1])%sz[i-1]+sz[i-1];
                x = cur;
            }
            cout << "1\n";
        }
        /*F0R(i, 6) cout << amt[i] << " ";
        cout << "\n";*/
    }

    return 0;
}