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
    int n, k, m;
    cin >> n >> k >> m;
    vector <vector <int> > a(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x % m].push_back(x);
    }
    for (int i = 0; i < m; i++) {
        if (a[i].size() >= k) {
            cout << "Yes\n";
            for (int j = 0; j < k; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "No\n";
}