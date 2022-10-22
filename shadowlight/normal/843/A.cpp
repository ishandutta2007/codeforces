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
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;
    sort(a.begin(), a.end());
    map <int, int> pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    vector <bool> used(n, 0);
    vector <vector <int> > data;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        int now = i;
        vector <int> kek;
        while (!used[now]) {
            used[now] = 1;
            kek.push_back(now);
            now = pos[b[now]];
        }
        data.push_back(kek);
    }
    cout << data.size() << "\n";
    for (auto x : data) {
        sort(x.begin(), x.end());
        cout << x.size() << " ";
        for (int i : x) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
}