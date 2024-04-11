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
int k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    cout << "3 3\n";
    cout << (1<<18)-1 << " " << (1<<17)-1 << " " << 0 << "\n";
    cout << (1<<17) << " " << (1<<18)-1 << " " << k << "\n";
    cout << 0 << " " << k << " " << k << "\n";
    
    return 0;
}