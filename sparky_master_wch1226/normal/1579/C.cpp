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
    int n, m, kk;
    cin >> n >> m >> kk;
    string arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    char cons[20][20];
    for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) cons[i][j] = '.';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == '.') continue;
            int k = 0;
            while(i > k && j > k && m - j - 1 > k && arr[i - k - 1][j - k - 1] == '*' && arr[i - k - 1][j + k + 1] == '*') k++;
            if(k >= kk) {
                //cout << i << ' ' << j << ' ' << k << '\n';
                for(int x = 0; x <= k; x++) {
                    cons[i - x][j - x] = '*';
                    cons[i - x][j + x] = '*';
                }
            }
        }
    }
    bool can = true;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(arr[i][j] != cons[i][j]) can =false;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) cout << cons[i][j];
    //     cout << '\n';
    // }
    cout << (can ? "YES\n" : "NO\n");
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}