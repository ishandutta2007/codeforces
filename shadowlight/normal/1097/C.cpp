#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    vector <string> a(n);
    map <int, int> data;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int minbal = 0, bal = 0;
        for (char c : a[i]) {
            if (c == '(') {
                bal++;
            } else {
                bal--;
            }
            minbal = min(bal, minbal);
        }
        if (bal >= 0) {
            if (minbal < 0) continue;
            data[bal]++;
        } else if (bal < 0) {
            if (minbal < bal) continue;
            data[bal]++;
        }
    }
    int res = 0;
    for (auto t : data) {
        if (t.first > 0) break;
        if (!t.first) {
            res += t.second / 2;
            break;
        }
        res += min(t.second, data[-t.first]);
    }
    cout << res;
}