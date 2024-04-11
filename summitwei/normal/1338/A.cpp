#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
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

#define MN 100005
int t;
int n;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        FOR(i, 1, n){
            cin >> a[i];
        }
        int mx = 0;
        FOR(i, 2, n){
            if(a[i] >= a[i-1]) continue;
            int d = a[i-1]-a[i];
            int res = __builtin_clz(d);
            int amt = 32-res;
            mx = max(mx, amt);
            a[i] = a[i-1];
        }
        cout << mx << "\n";
    }
    
    return 0;
}