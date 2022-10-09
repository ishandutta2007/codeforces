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
        int n; cin >> n;
        string s; cin >> s;
        for(int i=0; i<n; i++){
            if(s[i]=='R'){
                cout << 'R';
            }
            else if(s[i]=='L'){
                cout << 'L';
            }
            else if(s[i]=='U'){
                cout << 'D';
            }
            else{
                cout << 'U';
            }
        }
        cout << ln;
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