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
        int n, m; cin >> n >> m;
        if(n%2==1 && m%2==1) cout << "Tonya" << ln;
        else if(n%2==1 && m%2==0) cout << "Burenka" << ln;
        else if(n%2==0 && m%2==1) cout << "Burenka" << ln;
        else cout << "Tonya" << ln;
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