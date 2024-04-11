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
 
#define MN 3505
int t;
int n, m, k;
int a[MN];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    F0R(_, t){
        cin >> n >> m >> k;
        k = min(k, m-1);
        F0R(i, n){
            cin >> a[i];
        }
 
        int ans = 0;
        FOR(amtL, 0, k){
            int amtR = k - amtL;
            int unk = m-1-k;
            int mn = INF;
            FOR(l1, 0, unk){
                int r1 = unk-l1;
                //cout << "checking " << amtL << " " << amtR << " " << l1 << " " << r1 << "\n";
                int res = max(a[amtL+l1], a[n-1-amtR-r1]);
                //cout << amtL+l1 << " " << n-1-amtR-r1 << "\n";
                mn = min(mn, res);
            }
            ans = max(ans, mn);
        }
 
        cout << ans << "\n";
    }
 
    return 0;
}