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
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
bool ip(int x){
    FOR(i, 2, sqrt(x+1)){
        if(x % i == 0 && x != i) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, n, n+(n/2)){
        if(ip(i)){
            cout << i << "\n";
            //break;
            FOR(j, 1, n-1){
                cout << j << " " << (j+1) << "\n";
            }
            cout << 1 << " " << n << "\n";
            FOR(j, 1, i-n){
                cout << j << " " << j+(n/2) << "\n";
            }
            break;
        }
    }
    

    return 0;
}