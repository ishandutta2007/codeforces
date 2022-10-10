#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e5 + 10;
ll possum;
ll a[MAX], df[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        df[i] = a[i] - a[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        if(df[i] > 0)
            possum += df[i];
    }


    auto ceil = [](ll x) {
        if(x >= 0) return (x + 1) / 2;
        return -(abs(x) / 2);
    };

    auto ans = [&]() {
        return ceil(possum + (df[1] <= 0 ? df[1] : 0));
    };

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cout << ans() << '\n';
        int l, r, x;
        cin >> l >> r >> x;
        if(df[l] > 0)
            possum -= df[l];
        df[l] += x;
        if(df[l] > 0)
            possum += df[l];

        r++;
        if(r > n)
            continue;
        if(df[r] > 0)
            possum -= df[r];
        df[r] -= x;
        if(df[r] > 0)
            possum += df[r];
    }
    cout << ans() << '\n';
}