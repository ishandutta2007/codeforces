#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n * 4);
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
        a[i + n * 2] = a[i];
        a[i + n * 3] = a[i];
        if (a[i] >= a[maxi]) {
            maxi = i + n;
        }
        if (a[i] <= a[mini]) {
            mini = i + n * 2;
        }
    }

    if (a[mini] * 2 >= a[maxi]) {
        for (int i = 0; i < n; ++i) {
            cout << "-1 ";
        }
        return 0;
    }

    vector<int> ans(n * 4, 0);
    vector<pair<int, int>> incseq;
    vector<pair<int, int>> decseq({ { INF, mini + 1 } });
    for (int ci = mini; ci >= 0; --ci) {
        while (incseq.size() > 0 && incseq.back().first >= a[ci]) {
            incseq.pop_back();
        }
        while (decseq.size() > 0 && decseq.back().first < a[ci]) {
            decseq.pop_back();
        }
        if (a[ci] <= a[ci + 1]) {
            ans[ci] = ans[ci + 1] + 1;
            incseq.push_back({ a[ci], ci });
            decseq.push_back({ a[ci], ci });
            continue;
        }
        int left = -1, righ = incseq.size();
        while (righ - left > 1) {
            int mid = (left + righ) / 2;
            if (incseq[mid].first * 2 < a[ci]) {
                left = mid;
            }
            else {
                righ = mid;
            }
        }
        ans[ci] = INF;
        if (left >= 0) {
            ans[ci] = incseq[left].second - ci;
        }
        ans[ci] = min(ans[ci], decseq.back().second - ci + ans[decseq.back().second]);
        incseq.push_back({ a[ci], ci });
        decseq.push_back({ a[ci], ci });
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}