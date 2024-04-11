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
        int arr[n];
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        if(sum%n==0){
            cout << 0 << ln;
        }
        else{
            cout << 1 << ln;
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