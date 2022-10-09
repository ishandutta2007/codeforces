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
        int c = 1;
        for(int i=2; i<n; i++){
            int a = i;
            int b = n-a-c;
            if(gcd(a, b)==c){
                cout << a << sp << b << sp << c << ln;
                break;
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