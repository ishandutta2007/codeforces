#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    string s;
    cin >> s;
    int q; 
    cin >> q;
    int n = s.length();
    s = "." + s;
    int arr[n + 5];
    arr[0] = 0;
    // for(int i = 1; i <= n; i++) {
    //     arr[i] = arr[i - 1] + (s[i] == '[' || s[i] == ']');
    // }
    // vector<int> aaa;
    // for(int i = 1; i <= n; i++) {
    //     if(s[i] == '[' || s[i] == ']') aaa.pb(i % 2);
    // }
    // int aaaa[n + 5];
    // int ps[n + 5];
    // ps[0] = 0;
    // for(int i = 0; i < aaa.size(); i++) {
    //     ps[i + 1] = ps[i];
    //     if(aaa[i] == 0) ps[i + 1]++;
    //     else ps[i + 1]--;
    // }
    // for(int i = 0; i <= n; i++) cout << arr[i] << ' '; cout << '\n';
    // for(auto x: aaa) cout << x; cout << '\n';
    for(int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1];
        if(s[i] == '[' || s[i] == ']') {
            if(i % 2) arr[i]++;
            else arr[i]--;
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << abs(arr[r] - arr[l - 1]) << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}