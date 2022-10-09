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
        vector<int> a(n);
		vector<int> b(n);
        int maxxa = 0; int maxxb = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            cin >> b[i];
            if(a[i]>b[i]) swap(a[i], b[i]);
            maxxa = max(maxxa, a[i]);
            maxxb = max(maxxb, b[i]);
        }
        cout << maxxa * maxxb << ln;

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