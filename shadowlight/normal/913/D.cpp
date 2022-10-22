#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <pair <int, int> > > a;
int n, t;
vector <int> res;

bool can(int cnt) {
    vector <pair <int, int> > all;
    for (int i = cnt; i <= n; i++) {
        for (auto p : a[i]) {
            all.push_back(p);
        }
    }
    sort(all.begin(), all.end());
    if (all.size() < cnt) return false;
    while (all.size() > cnt) all.pop_back();
    int sum = 0;
    for (auto p : all) {
        sum += p.first;
    }
    if (sum > t) {
        return false;
    }
    res.clear();
    for (auto p : all) {
        res.push_back(p.second);
    }
    return true;
}

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
    cin >> n >> t;
    a.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int x, t;
        cin >> x >> t;
        a[x].push_back({t, i});
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (!can(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << "\n";
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x + 1 << " ";
    }
}