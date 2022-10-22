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
    vector <int> a(n), c(n);
    vector <bool> used(n, false);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        vector <int> st;
        int now = i;
        while (!used[now]) {
            st.push_back(now);
            used[now] = true;
            now = a[now];
        }
        int minc = c[now];
        while (st.size() && st.back() != now) {
            minc = min(minc, c[st.back()]);
            st.pop_back();
        }
        if (st.size()) {
            res += minc;
        }
    }
    cout << res;
}