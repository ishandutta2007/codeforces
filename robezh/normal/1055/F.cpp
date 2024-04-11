#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

int n;
ll k;
ll a[N], f[N], tmp[N];
ll res, all;

void change(int i) {
    int l = 0, r = 0;
    ll rest = all ^ (1LL << i);
    for(int j = 0; j < n; j = r) {
        r = l = j;
        while(l < n && (f[j]&all) == (f[l]&all)) l++;
        while(r < n && (f[j]&rest) == (f[r]&rest)) r++;
        int ci = j;
        for(int k = l; k < r; k++) tmp[ci++] = f[k];
        for(int k = j; k < l; k++) tmp[ci++] = f[k];
        for(int k = j; k < r; k++) f[k] = tmp[k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p; p--;
        ll x;
        cin >> x;
        a[i] = a[p] ^ x;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) f[i] = a[i];

    for(int b = 61; b >= 0; b--) {
        int l = 0, r = 0;
        all |= (1LL << b);
        ll s = 0;
        for(int i = 0; i < n; i++) {
            ll cur = (f[i] ^ res) & all;
            while(l < n && (a[l] & all) < cur) l++;
            while(r < n && (a[r] & all) <= cur) r++;
            s += r - l;
        }
        if(s < k) {
            k -= s;
            change(b);
            res |= (1LL << b);
        }
    }
    cout << res << endl;
}