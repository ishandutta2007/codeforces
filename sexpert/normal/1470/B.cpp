#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*

x = prod a_i^b_i, y = prod a_i^c_i
b_i = c_i (mod 2)

*/

const int MAX = 1e6 + 5;
int pr[MAX];

int redu(int x) {
    int res = 1;
    while(x > 1) {
        int p = pr[x], e = 0;
        while(x % p == 0) {
            x /= p;
            e++;
        }
        if(e % 2 == 1)
            res *= p;
    }
    return res;
}

void solve() {
    map<int, int> cnt;
    int n;
    cin >> n;
    int modd = 0, seven = 0, mx = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[redu(x)]++;
    }
    for(auto &[x, c] : cnt) {
        if(x == 1) {
            mx = max(mx, c);
            seven += c;
            continue;
        }
        if(c % 2 == 1)
            modd = max(modd, c);
        else
            seven += c;
        mx = max(mx, c);
    }
    int q;
    cin >> q;
    while(q--) {
        ll w;
        cin >> w;
        if(w == 0)
            cout << mx << '\n';
        else
            cout << max(modd, seven) << '\n';
    }
}

void sieve() {
    for(int p = 2; p < MAX; p++) {
        if(pr[p] == 0) {
            for(int q = p; q < MAX; q += p)
                pr[q] = p;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int t;
    cin >> t;
    while(t--)
        solve();
}