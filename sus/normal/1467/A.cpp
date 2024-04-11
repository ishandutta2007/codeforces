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
        int n; cin >> n;
        if(n==1){
            cout << 9 << ln;
        }
        else if(n==2){
            cout << 98 << ln;
        }
        else{
            cout << 989;
            int u = n-3;
            int r = 0;
            while(u>0){
                cout << r;
                if(r==9){
                    r=0;
                }
                else{
                    r++;
                }
                u--;
            }
            cout << ln;
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