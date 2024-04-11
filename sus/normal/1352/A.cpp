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
        int n; cin >> n;
        int z = 0;
        int x = 0;
        int y = n;
        while(y>0){
            int r = y%10;
            if(r!=0){
                x++;
            }
            y = y/10;
        }
        cout << x << ln;
        while(n>0){
            int r = n%10;
            if(r!=0){
                cout << r;
                for(int i=0; i<z; i++){
                    cout << 0;
                }
                cout << sp;
            }
            n = n/10;
            z++;
        }
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