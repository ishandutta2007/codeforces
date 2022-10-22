#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n;
    cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector <int> used(n, 0);
    vector <int> cycles;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int now = i;
        if (used[i]) continue;
        while (!used[now]) {
            used[now] = true;
            cnt++;
            now = p[now];
        }
        //cout << "\n";
        cycles.push_back(cnt);
    }
    sort(cycles.begin(), cycles.end());
    if (cycles.size() >= 2) {
        int x = cycles.back();
        cycles.pop_back();
        cycles.back() += x;
    }
    ll res = 0;
    for (ll x : cycles) {
        res += x * x;
    }
    cout << res;
}