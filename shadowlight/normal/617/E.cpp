#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2 * 1e6;

bool cmp(pair <pair <int, int>, int> &a, pair <pair <int, int>, int> &b) {
    return a.first.first < b.first.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }
    int len = sqrt(1e5);
    vector <pair <pair <int, int>, int> > z;
    vector <ll> ans(m, 0);
    vector <int> cnt(MAXN, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 <= len) {
            ll sum = 0;
            cnt[pref[l - 1]] = 1;
            for (int j = l; j <= r; j++) {
                sum += cnt[pref[j] ^ k];
                cnt[pref[j]]++;
            }
            for (int j = l; j <= r; j++) {
                cnt[pref[j]]--;
            }
            cnt[pref[l - 1]] = 0;
            ans[i] = sum;
        } else {
            z.push_back({{l, r}, i});
        }
    }
    sort(z.begin(), z.end(), cmp);
    int now = 0;
    int i = 0;
    while (i < z.size()) {
        //cout << now << endl;
        vector <pair <pair <int, int>, int> > data;
        while (i < z.size() && z[i].first.first < now + len) {
            data.push_back({{z[i].first.second, z[i].first.first}, z[i].second});
            i++;
        }
        vector <int> cnt(MAXN, 0);
        ll sum = 0;
        sort(data.begin(), data.end(), cmp);
        int prev = now + len;
        for (int j = 0; j < data.size(); j++) {
            int l = data[j].first.second, r = data[j].first.first;
            int id = data[j].second;
            for (int e = prev; e <= r; e++) {
                sum += cnt[pref[e] ^ k];
                cnt[pref[e]]++;
            }
            ll sum1 = sum;
            for (int e = now + len - 1; e >= l - 1; e--) {
                sum1 += cnt[pref[e] ^ k];
                cnt[pref[e]]++;
            }
            for (int e = now + len - 1; e >= l - 1; e--) {
                cnt[pref[e]]--;
            }
            ans[id] = sum1;
            prev = r + 1;
        }
        now += len;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
}