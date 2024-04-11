#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int mx = *max_element(a.begin(), a.end());

    vector<int> minD(mx + 1, -1);
    for (int i = 2; i <= mx; i++) {
        if (minD[i] != -1) continue;
        if (i > 10000) continue;
        for (int j = i * i; j <= mx; j += i)
            if (minD[j] == -1) minD[j] = i;
    }

    vector<int> ans1(n, -1);
    vector<int> ans2(n, -1);

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int d = minD[x];
        if (d == -1) continue;
        while (x % d == 0) x /= d;
        if (x > 1) {
            ans1[i] = x;
            ans2[i] = d;
        }
    }

    for (int i = 0; i < n; i++) cout << ans1[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << ans2[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    cout << "Time = " << (double)clock() / CLOCKS_PER_SEC << endl;
    int T = 1;
    for (int i = 1; i < T; i++) solve();    
#endif
}