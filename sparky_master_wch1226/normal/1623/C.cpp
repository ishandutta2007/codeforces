#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
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
int n, arr[200005];
int arr2[200005];
int arr3[200005];
bool can(int k) {
    for(int i = 0; i < n; i++) arr[i] = arr2[i], arr3[i] = 0;
    for(int i = n - 1; i >= 2; i--) {
        if(arr[i] + arr3[i] < k) return false;
        int d = (arr[i] + arr3[i] - k) / 3;
        d = min(d, arr[i] / 3);
        arr3[i - 1] += d;
        arr3[i - 2] += d * 2;
    }
    return arr[0] + arr3[0] >= k && arr[1] + arr3[1] >= k;
}
void solve(int TC) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr2[i];
    int l = 0, r = 1e9;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(can(m)) l = m;
        else r = m - 1;
    }
    cout << l << '\n';
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