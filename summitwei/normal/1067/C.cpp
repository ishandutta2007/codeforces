#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000LL
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n <= 10){
        F0R(i, n){
            cout << i << " " << i << "\n";
        }
        return 0;
    }
    int v = (n+5)/3;
    cout << "0 0\n";
    int x = 1;
    FOR(i, 1, v-1){
        cout << i << " 0\n0 " << i << "\n";
        if(i <= v-3 && i != 2){
            cout << i << " " << i << "\n";
        }
    }
    if(n % 3 == 2){
        cout << v-2 << " " << v-2 << "\n";
    }
    if(n % 3 == 0){
        cout << v-2 << " " << v-2 << "\n";
        cout << v << " 0\n";
    }

    return 0;
}