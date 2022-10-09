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
        int e = 0;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=1; i<n-1; i++) {
            if(arr[i]<=1) e++;
        }
        if(e==n-2 || (n==3 && arr[1]%2!=0)) cout << -1 << ln;
        else{
            ll s = 0;
            for(int i=1; i<n-1; i++) s+=(arr[i]+1)/2;
            cout << s << ln;
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