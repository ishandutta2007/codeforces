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

#define MN 1005
int n;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int a = -INF;
    F0R(i, n){
        int x;
        cin >> x;
        if(x < 0){
            a = max(a, x);
            continue;
        }
        int rt = (int)(sqrt(x));
        if(rt*rt != x) a = max(a, x);
    }
    cout << a << "\n";

    return 0;
}