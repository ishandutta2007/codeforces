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
        string s; cin >> s;
        int n = s.length();
    
        vi cnt(26);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (cnt[c] < 2) {
                cnt[c]++;
                ans++;
            }
        }
    
        ans /= 2;
        cout << ans << ln;
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