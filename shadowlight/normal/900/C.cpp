#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    set <int> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.insert(a[i]);
    }
    vector <int> good(n + 1, 0);
    vector <int> rec(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i];
        q.erase(x);
        auto it = q.rbegin();
        int cnt = 0;
        int el = -1;
        while (cnt < 2 && cnt < q.size() && *it > x) {
            cnt++;
            el = *it;
            it--;
        }
        if (!cnt) {
            rec[i] = 1;
        }
        if (cnt != 1) {
            continue;
        }
        good[el]++;
    }
    int maxk = -INF, pos = -1;
    for (int i = 0; i < n; i++) {
        if (good[a[i]] - rec[i] > maxk) {
            maxk = good[a[i]] - rec[i];
            pos = a[i];
        } else if (good[a[i]] - rec[i] == maxk) {
            pos = min(pos, a[i]);
        }
    }
    cout << pos;
}