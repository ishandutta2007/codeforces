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
int arr[45];
vector<int> idk;
void factors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) idk.pb(i);
            else {
                idk.pb(i);
                idk.pb(n / i);
            }
        }
    }
    return;
}
void solve(int TC) {
    idk.clear();
    int n;
    cin >> n;
    int mi = 10000000;
    int ma = -10000000;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += 1000000;
        // mi = min(mi, arr[i]);
        // ma = max(ma, arr[i]);
    }
    if(mi == ma) {
        cout << "-1\n";
        return;
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] != arr[j]) factors(arr[j] - arr[i]);
        }
    }
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cnt[arr[i]]++;
    }
    for(auto x: cnt) {
        if(x.se >= n / 2) {
            cout << -1 << '\n';
            return;
        }
    }
    cnt.clear();
    sort(idk.begin(), idk.end());
    reverse(idk.begin(), idk.end());
    for(auto i: idk) {
        cnt.clear();
        for(int j = 0; j < n; j++) {
            cnt[arr[j] % i]++;
        }
        for(auto x: cnt) {
            if(x.se >= n / 2) {
                cout << i << '\n';
                return;
            }
        }
    }
    // int ans = 1;
    // for(int i = 0; i <= n / 2; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //         if(arr[i] == arr[j]) continue;
    //         vector<int> aaaa = factors(arr[j] - arr[i]);
    //         for(auto x: aaaa) {
    //             int diff = x;
    //             int cnt = 1;
    //             for(int k = i + 1; k < n; k++) {
    //                 if((arr[k] - arr[i]) % diff == 0) cnt++;
    //             }
    //             if(cnt >= n / 2) ans = max(ans, cnt);
    //             cout << i << ' ' << j << ' ' << x << ' ' << cnt << '\n';
    //         }
    //     }
    // }
    // cout << ans << '\n';
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