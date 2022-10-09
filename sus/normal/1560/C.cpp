#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        ll ans = ceil((double)sqrt(n));
        ll curr  = sqrt(n);
        curr*=curr;
        if(n - curr == 0){
            cout << ans << sp << 1 << ln;
        }
        else if(n-curr<=ans) {
            cout << n-curr << sp <<ans << ln;
        }
        else{
            ll fakeans = ans*ans;
            cout << ans << sp << fakeans-n+1 << ln;
        }
    }
 
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}