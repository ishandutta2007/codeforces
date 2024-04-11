//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;
int p[N], sz[N];

int fnd(int v) {
    return (p[v] == v ? v : fnd(p[v]));
}

void uniq(int v1, int v2) {
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (v1 == v2) return;
    p[v1] = v2;
    sz[v2] += sz[v1];
}

int a[N];

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i;
        sz[i] = 1;
        mp[a[i]].push_back(i);
    }

    int tot = 0, lst = -1;
    int ansL = 1;
    int ansK = mp.rbegin()->first;
    map<int, int> num;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto v = it->second;
        for (int ps: v) {
            tot++;
            num[1]++;
            lst = 1;
            if (ps > 0 && a[ps] >= a[ps - 1]) {
                int v1 = fnd(ps);
                int v2 = fnd(ps - 1);
                if (v1 != v2) {
                    tot--;
                    num[sz[v1]]--;
                    num[sz[v2]]--;
                    uniq(v1, v2);
                    lst = sz[fnd(ps)];
                    num[lst]++;
                }
            }
            if (ps + 1 < n && a[ps] >= a[ps + 1]) {
                int v1 = fnd(ps);
                int v2 = fnd(ps + 1);
                if (v1 != v2) {
                    tot--;
                    num[sz[v1]]--;
                    num[sz[v2]]--;
                    uniq(v1, v2);
                    lst = sz[fnd(ps)];
                    num[lst]++;
                }
            }
        }
        if (tot == num[lst]) {
            int curK = it->first;
            int curL = num[lst];
            if (curL > ansL || (curL == ansL && curK < ansK)) {
                ansL = curL;
                ansK = curK;
            }
        }
    }
    cout << ansK + 1 << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    solve();
#endif
    solve();
    return 0;
}