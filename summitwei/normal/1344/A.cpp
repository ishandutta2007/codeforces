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

#define MN 200005
int t;
int n;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        F0R(i, n){
            int x;
            cin >> x;
            a[i] = (x%n+n+i)%n;
        }
        sort(a, a+n);
        bool ok = true;
        if(a[0] != 0) ok = false;
        F0R(i, n-1){
            if(a[i]+1 != a[i+1]){ ok = false; break; }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}