#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)2e5 + 50, mod = 998244353;

int n, k;
int a[N];
ll res = 0, cnt = 1;
int in[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(n - k + 1 <= a[i] && a[i] <= n) {
            in[i] = 1;
            res += a[i];
        }
    }
    int la = -1;
    for(int i = 0; i < n; i++) {
        if(in[i]) {
            if(la != -1) cnt = (cnt * (i - la)) % mod;
            la = i;
        }
    }
    cout << res << " " << cnt << '\n';

}