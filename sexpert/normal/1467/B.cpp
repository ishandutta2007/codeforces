#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;

    auto va = [](int a, int b, int c) {
        if(a < b && b > c)
            return 1;
        if(a > b && b < c)
            return -1;
        return 0;
    };

    vector<int> sc(n);
    for(int i = 1; i + 1 < n; i++) {
        sc[i] = va(v[i - 1], v[i], v[i + 1]);
    }
    int df = 0;
    for(auto &x : sc)
        df += abs(x);

    int ans = df;

    //cout << df << '\n';

    //for(int i = 0; i < n; i++)
    //    cout << sc[i] << " ";
    //cout << '\n';

    if(ans == 0) {
        cout << "0\n";
        return;
    }

    int wow;
    for(int i = 0; i + 2 < n; i++) {
        int tk = abs(sc[i]) + abs(sc[i + 1]) + abs(sc[i + 2]);
        if(i >= 1 && i + 3 < n) {
            if(v[i] > v[i - 1] && v[i] > v[i + 2] && v[i + 2] < v[i + 3])
                tk--;
            if(v[i] < v[i - 1] && v[i] < v[i + 2] && v[i + 2] > v[i + 3])
                tk--;
        }
        wow = max(wow, tk);
    }

    cout << ans - wow << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
       solve();
}