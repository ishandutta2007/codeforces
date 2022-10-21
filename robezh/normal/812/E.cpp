#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, M = (int)3e7 + 50;

int n;
vector<int> G[N];
int a[N];
int cnt[M];
int cnt0 = 0;
int dep[N];
int mx = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        dep[i] = dep[p] + 1;
        mx = max(dep[i], mx);
    }
    int xorsum = 0;
    for(int i = 0; i < n; i++) {
        if(dep[i] % 2 == mx % 2) {
            cnt0 ++;
            xorsum ^= a[i];
        }
        else {
            cnt[a[i]]++;
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(dep[i] % 2 == mx % 2) {
            res += cnt[xorsum ^ a[i]];
        }
    }
    if(xorsum == 0) {
        res += 1LL * cnt0 * (cnt0 - 1) / 2;
        res += 1LL * (n - cnt0) * (n - cnt0 - 1) / 2;
    }
    cout << res << endl;

}