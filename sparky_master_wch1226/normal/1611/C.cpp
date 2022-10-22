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
    deque<int> cons;
    int n;
    cin >> n;
    int arr[n + 5];
    int t;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int lpt = 0, rpt = n - 1;
    if(arr[lpt] != n && arr[rpt] != n) {
        cout << "-1\n";
        return;
    }
    else if(arr[lpt] == n) lpt++;
    else rpt--;
    cons.pb(n);
    for(int i = lpt; arr[i] != n - 1 && i <= rpt; i++) {
        cons.push_front(arr[i]);
        lpt++;
    }
    for(int i = rpt; i >= lpt; i--) {
        cons.pb(arr[i]);
    }
    for(int i = 0; i < n; i++) cout << cons[i] << ' ';
    cout << '\n';
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