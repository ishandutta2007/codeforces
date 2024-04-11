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
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<pair<int, int>> ans;
    for(int i = 0; i < n - 1; i++) {
        int mi = 2000000000;
        int id = -1;
        for(int j = i; j < n; j++) {
            if(arr[j] < mi) {
                id = j;
                mi = arr[j];
            }
        }
        if(id != i) {
            ans.pb(mp(i, id));
            for(int j = id; j >= i + 1; j--) arr[j] = arr[j - 1];
            arr[i] = mi;
        }
        //for(int j = 0; j < n; j++) cout << arr[j] << ' ';cout << '\n';
    }
    cout << ans.size() << '\n';
    for(auto x: ans) {
        cout << x.fi + 1 << ' ' << x.se + 1 << ' ' << x.se - x.fi << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}