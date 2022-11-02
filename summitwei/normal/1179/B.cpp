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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
int n, m;
int xch[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 1, n-1){
        if(i % 2 == 1) xch[i] = (n-i);
        else xch[i] = -(n-i);
    }
    int l = 1, r = m;
    int cx = 1;
    bool on = false;
    while(l <= r){
        cx = 1;
        cout << cx << " " << l << "\n";
        on = true;
        FOR(i, 1, n-1){
            cx += xch[i];
            cout << cx << " ";
            /*if(i % 2 == 1) cout << r << "\n";
            else cout << l << "\n";*/
            if(on) cout << r << "\n";
            else cout << l << "\n";

            on = !on;
        }
        if(l == r) break;

        cout << cx << " ";// << r << "\n";
        cout << (on ? r : l) << "\n";
        on = !on;
        RFOR(i, n-1, 1){
            cx -= xch[i];
            cout << cx << " ";
            /*if((i % 2 == 1) == (n % 2 == 1)) cout << r << "\n";
            else cout << l << "\n";*/
            cout << (on ? r : l) << "\n";
            on = !on;
        }

        l++;
        r--;
    }
    
    return 0;
}