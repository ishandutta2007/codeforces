#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;

vector<ll> t;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    t.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<ll> pr(n);
    pr[0] = t[0];
    for (int i = 1; i < n; ++i) {
        pr[i] = pr[i - 1] + t[i];
    }
    vector<pair<int, int>> sob;
    vector<ll> res(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= t[i]) {
            res[i] += a[i];
            continue;
        }
        if (pr.back() - pr[i] + t[i] <= a[i]) {
            sob.push_back(make_pair(i, 1));
        } else {
            int left = i;
            int right = n;
            while (right - left > 1) {
                int mid = (right + left) / 2;
                if (pr[mid] - pr[i] + t[i] <= a[i]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            sob.push_back(make_pair(i, 1));
            sob.push_back(make_pair(left + 1, -1));
            res[right] += a[i] - (pr[left] - pr[i] + t[i]);
        }
    }
    sort(sob.begin(), sob.end());
    sob.push_back(make_pair(n + 1, 0));
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (i >= sob[j].first) {
            cnt += sob[j].second;
            ++j;
        }
        res[i] += cnt * t[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}