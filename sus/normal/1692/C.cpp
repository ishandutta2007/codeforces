#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
void solve2(char arr[8][8]){
    for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(arr[i][j]=='#' && arr[i][j+2]=='#'){
                    cout << i+2 << sp << j+2 << ln;
                    return;
                }
            }
        }
}
void solve(){
    int t; cin >> t;
    while(t--){
        char arr[8][8];
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cin >> arr[i][j];
            }
        }
        solve2(arr);
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