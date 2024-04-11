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
    int n, k;
    cin >> n >> k;
    vector <int> a(k);
    vector <int> exist(n + 1, 0);
    set <int> q;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        q.insert(a[i]);
        exist[a[i]] = 1;
    }
    int maxk = -1, mink = INF;
    int pa = -1;
    for (int i = k - 1; i >= 0; i--) {
        if (maxk > a[i]) {
            pa = max(pa, a[i]);
        }
        if (mink < a[i]) {
            auto it = q.upper_bound(mink);
            if (*it < a[i]) {
                cout << -1;
                return 0;
            }
        }
        q.erase(a[i]);
        mink = min(mink, a[i]);
        maxk = max(maxk, a[i]);
    }
    auto b = a;
    sort(b.begin(), b.end());
    for (int i = 1; i <= n; i++) {
        if (exist[i]) continue;
        if (pa > i) {
            cout << -1;
            return 0;
        }
    }
    for (int i = b[0] - 1; i >= 1; i--) {
        a.push_back(i);
    }
    for (int i = 1; i < k; i++) {
        for (int x = b[i] - 1; x > b[i - 1]; x--) {
            a.push_back(x);
        }
    }
    for (int i = n; i > b.back(); i--) {
        a.push_back(i);
    }
    for (int x : a) {
        cout << x << " ";
    }
}