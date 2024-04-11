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
    map <string, int> num;
    int n, k, m;
    cin >> n >> k >> m;
    vector <string> a(n);
    vector <int> val(n, 0), c(k, INF);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = s;
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int p;
            cin >> p;
            p--;
            num[a[p]] = i;
            c[i] = min(c[i], val[p]);
        }
    }
    ll res = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        res += c[num[s]];
    }
    cout << res;
}