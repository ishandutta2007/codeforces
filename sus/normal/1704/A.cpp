#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    
        int n, m; cin >> n >> m;
        string a, b; cin >> a >> b;
        bool f = false;
        if(a.substr(n-(m-1))==b.substr(1)){
            for(int i=0; i<n-(m-1); i++){
                if(a[i]==b[0]){
                   yes;
                   return;
                }
            }
        }
        no;
        
    
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
    solve();
    }
}