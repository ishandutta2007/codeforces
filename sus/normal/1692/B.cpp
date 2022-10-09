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
        int arr[n]; 
        for(int i=0; i<n; i++) cin >> arr[i];
        int maxx = arr[0];
        for(int i=0; i<n; i++){
            maxx = max(maxx, arr[i]);
        }
        int ee[maxx];
        for(int i=0; i<maxx; i++) ee[i] = 0;
        for(int i=0; i<n; i++){
           ee[arr[i]-1]++;
        }
        int r = 0;
        for(int i=0; i<maxx; i++){
            if(ee[i]>=1) r++;
        }
        //cout << nfsp << sp << nfdp << ln;
        if(r%2==n%2) cout << r << ln;
        else cout << r-1 << ln;
        
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