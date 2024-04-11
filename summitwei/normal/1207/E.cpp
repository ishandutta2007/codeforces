#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
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

#define MN 100


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cout << "? ";
    FOR(i, 1, 100){
        cout << i << " ";
    }
    cout << endl;
    cout.flush();
    int resp1;
    cin >> resp1;

    cout << "? ";
    FOR(i, 1, 100){
        cout << i*128 << " ";
    }
    cout << endl;
    cout.flush();
    int resp2;
    cin >> resp2;

    int xr = resp1 ^ resp2;
    int ree = (xr/128)*128;
    cout << "! " << (resp2 ^ ree) << endl;
    cout.flush();

    return 0;
}