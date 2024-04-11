#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        int r = log2(n - 1);
        ll y = (1ll << r);
        for(int i = y-1; i >= 0;i--) cout << i << sp;
        for(int i = y; i < n; i++) cout << i << sp;
        cout << ln;
 
    }

    
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}