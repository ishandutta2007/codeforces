#include <bits/stdc++.h>
using namespace std;

int n;
long long s;
pair<int, int> a[200000];

bool check(int m) {
    int cnt = 0;
    long long tot = 0;
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (a[i].second < m)
            tot += a[i].first;
        else if (a[i].first >= m) {
            tot += a[i].first;
            cnt++;
        } else
            v.push_back(a[i].first);
    }

    int need = max(0, (n + 1) / 2 - cnt);
    if (need > v.size())
        return false;
    for (int i=0; i<v.size(); i++) {
        if (i < v.size() - need)
            tot += v[i];
        else
            tot += m;
    }

    return tot <= s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i=0; i<n; i++)
            cin >> a[i].first >> a[i].second;

        sort(a, a + n);

        int l = 1, r = 1000000001;
        while (l < r) {
            int m = (l + r) / 2;
            if (check(m))
                l = m + 1;
            else
                r = m;
        }

        cout << l - 1 << "\n";
    }

    return 0;
}