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
        int k; cin >> k;
        double e = 2.0;
        int ans = 0;
        int q = ceil(n/e);
        if(k>q){
            cout << -1 << ln;
        }
        else {
            for(int i=0; i<n; i++){
                for(int j=0; j<n;j++){
                    if(i%2==0 && i==j && ans<k && j%2==0){
                        cout << 'R';
                        ans++;
                    }
                    else{
                        cout << '.';
                    }
                }
                cout << ln;
            }
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