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
        int n = s.size();
        int x = -1, y = -1;
        for(int i = 0; i<n-1; i++) {
            int r = (s[i] - '0' + s[i + 1] - '0');
            if (r<= 9) {
                if (x != -1) continue;
                x = i;
            }
            if (r > 9) {
                y = i;
            }
        }
        if (y != -1) {
            int r = (s[y] - '0' + s[y + 1] - '0');
            s.erase(y, 2);
            s.insert(y, to_string(r));
        } 
        else {
            int r = (s[x] - '0' + s[x + 1] - '0');
            s.erase(x, 2);
            s.insert(x, to_string(r));
        }
        cout << s << ln;
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