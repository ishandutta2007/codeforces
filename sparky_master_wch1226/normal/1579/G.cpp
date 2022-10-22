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
int n;
bool can(int a, vector<int> arr) {
    bool reach[n + 5][a + 5];
    memset(reach, false, sizeof reach);
    for(int i = 0; i <= a; i++) reach[0][i] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= a; j++) {
            if(!reach[i][j]) continue;
            if(j - arr[i] >= 0) reach[i + 1][j - arr[i]] = true; 
            if(j + arr[i] <= a) reach[i + 1][j + arr[i]] = true; 
        }
    }
    for(int i = 0; i < a; i++) if(reach[n][i] == true) return true;
    return false;
}
void solve(int TC) {
    //int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 2000;
    while(l < r) {
        int m = (l + r) / 2;
        if(!can(m, arr)) l = m + 1;
        else r = m;
    }
    cout << l << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}