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
        int a; cin >> a;
        int b; cin >> b; 
        int c; cin >> c;
        ll possible = 2*abs(b-a);
        int ans = 0;
 
        if (b > possible || a > possible || c > possible) {
            ans = -1;
        }

        else {
            ans = c + possible/2;
            if (ans > possible){
                ans = c-possible/2;
            }
        }
 
        cout << ans << ln;
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