#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
int cnt[2], a[MAXN], n, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            cnt[a[x]]--;
            a[x] ^= 1;
            cnt[a[x]]++;
        }
        if(t == 2) {
            if(x <= cnt[1])
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}