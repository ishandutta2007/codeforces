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
        string s; cin >> s;
        string test = "";
        test += s[0];
        for(int i = 1; i< n;i ++){
            if((s[i-1] == s[i] && i>1) || (s[i-1] > s[i])){
                test += s[i]; 
            }
            else break;
        }
        cout << test; 
        reverse(test.begin(),test.end()); 
        cout << test << ln; 
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