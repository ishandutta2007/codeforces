#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    int n, k, m, a;
    cin >> n >> k >> m >> a;
    vector<int> g(a);
    for (int i = 0; i < a; i++) {
        cin >> g[i];
        g[i]--;
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> cnt(n);
    vector<int> last(n);
    for (int i = 0; i < a; i++) {
        cnt[g[i]]++;
        last[g[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int kek = 0;
        for (int j = 0; j < n; j++) {
            if (j != i && cnt[j] > 0 && (cnt[j] > cnt[i] + m - a || (cnt[j] == cnt[i] + m - a && (m > a || last[i] > last[j])))) {
                kek++;
            }
        }
        bool canwin = kek < k && cnt[i] + m - a > 0;

        vector<int> mem;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last[j] < last[i])) {
                mem.push_back(0);
                continue;
            }
            mem.push_back(cnt[i] - cnt[j] + 1);
        }
        sort(mem.begin(), mem.end());

        int left = m - a;
        int lol = 0;
        for (int j = 0; j < mem.size(); j++) {
            if (mem[j] <= left) {
                left -= mem[j];
                lol++;
            }
        }
        bool cansuck = lol >= k || cnt[i] == 0;

        if (canwin && cansuck) {
            cout << 2 << " ";
        } else if (canwin) {
            cout << 1 << " ";
        } else {
            cout << 3 << " ";
        }
    }
    cout << endl;

    return 0;
}