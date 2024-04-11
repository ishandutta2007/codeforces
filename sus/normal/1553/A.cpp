//  sathu
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
        ll n; cin >> n;
        if(n<9){
            cout << 0 << ln;
        }
        else if(n<=18 && n>=9){
            cout << 1 << ln;
        }
        else{
            ll sus = ceil(n/10);
            if(n%10==9) sus++;
            cout << (sus) << ln;
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