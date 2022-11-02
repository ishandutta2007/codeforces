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

#define MN 505
int n, k;
ll a[MN], b[MN];
ll ans;
bool ok[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ok[0][0] = true;

    ll rem = 0;

    cin >> n >> k;
    F0R(i, n){
        //cout << "doing " << i << "\n";
        cin >> a[i] >> b[i];
        //ans += (a[i]/k); a[i] %= k;
        //ans += (b[i]/k); b[i] %= k;
        ans += (a[i]+b[i]);
        rem = (rem+a[i]+b[i])%k;
        F0R(j, k){
            if(a[i] < j) continue;
            int ot = (a[i]+b[i]-j)%k;
            if(b[i] < ot) continue;
            //cout << "can get rem of " << j << "\n";
            F0R(cur, k){
                ok[i+1][(cur+j)%k] |= ok[i][cur];
            }
        }
    }
    bool gwovoyayy = false;
    F0R(i, rem+1){
        if(ok[n][i]){
            gwovoyayy = true;
            break;
        }
    }
    cout << ans/k-1+gwovoyayy << "\n";
    
    return 0;
}