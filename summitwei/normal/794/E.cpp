#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
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
int a[MN];
int ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int mx = 0;
    F0R(i, n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ans[n-1] = mx;
    
    F0R(i, n-1){
        int l = (n-i)/2, r = (n+i)/2;
        if((n-i) % 2 == 0){
            ans[i] = max(max(a[l], a[l-1]), max(a[r], a[r]-1));
        } else{
            int v1 = min(max(a[l-1], a[l+1]), a[l]), v2 = min(max(a[r-1], a[r+1]), a[r]);
            ans[i] = max(v1, v2);
        }
        if(i >= 2) ans[i] = max(ans[i], ans[i-2]);
    }
    
    F0R(i, n){
        cout << ans[i] << " ";
    }

    return 0;
}