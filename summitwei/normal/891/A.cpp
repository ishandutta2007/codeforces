#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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

#define MN 2005
int n;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int oc = 0;
    FOR(i, 1, n){
        cin >> a[i];
        if(a[i] == 1) ++oc;
    }
    if(oc){
        cout << n-oc << "\n";
        return 0;
    }
    int mn = n+1;
    FOR(i, 1, n){
        int cg = 0;
        FOR(j, i, n){
            cg = __gcd(cg, a[j]);
            if(cg == 1){
                mn = min(mn, j-i+1);
                break;
            }
        }
    }
    if(mn == n+1){
        cout << "-1\n";
    } else{
        cout << n+mn-2 << "\n";
    }
    
    return 0;
}