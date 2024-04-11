#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(a) (a).begin(), (a).end()
#define ll long long

int a[1005][1005];
int cnt[1005];
vector<int> v[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int mm = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            v[i].clear();
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= mm) v[i].pb(j);
            }
        }
        bool f = 0;
        for (int j = 0; j < m; j++) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) {
                if (f) break;
                if (a[i][j] >= mm) {
                    for (auto jj : v[i]) {
                        if (jj == j) continue;
                        cnt[jj]++;
                        if (cnt[jj] >= 2) {
                            f = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (f) l = mm; else r = mm;
    }
    cout << l;
    return 0;
}