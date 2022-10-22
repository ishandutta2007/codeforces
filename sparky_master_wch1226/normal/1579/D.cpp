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
    pair<int, int> arr[n + 5];
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> mx;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].fi;
        arr[i].se = i + 1;
        if(arr[i].fi > 0) mx.push(arr[i]);
    }
    sort(arr, arr + n);
    vector<pair<int, int>> ans;
    int lp = 0, rp = n - 1;
    while(mx.size() >= 2) {
        pair<int, int> a = mx.top(); mx.pop();
        pair<int, int> b = mx.top(); mx.pop();
        ans.pb(mp(a.se, b.se));
        a.fi--; b.fi--;
        if(a.fi > 0) mx.push(a);
        if(b.fi > 0) mx.push(b);
    }
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x.fi << ' ' << x.se << '\n';
}   
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}