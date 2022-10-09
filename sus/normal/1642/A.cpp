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
        int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if(y3==y2){
            if(y3>y1){
                //cout << "t1" << ln;
                cout << abs(x3-x2) << ln;
            }
            else{
           // cout << "t4" << ln;
            cout << 0 << ln;
        }
        }
        else if (y1==y2){
            if(y1>y3){
               // cout << "t2" << ln;
                cout << abs(x1-x2) << ln;
            }
            else{
           // cout << "t4" << ln;
            cout << 0 << ln;
        }
        }
        else if(y1==y3){
            if(y1>y2){
              //  cout << "t3" << ln;
                cout << abs(x3-x1) << ln;
            }
            else{
           // cout << "t4" << ln;
            cout << 0 << ln;
        }
        }
        else{
           // cout << "t4" << ln;
            cout << 0 << ln;
        }
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