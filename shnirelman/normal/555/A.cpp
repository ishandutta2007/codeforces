#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
4 1
4 1 2 3 4

4 4
1 1
1 2
1 3
1 4

1 1
1 1
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(k);
    for(int i = 0; i < k; i++) {
        int m;
        cin >> m;

        a[i].resize(m);
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int ans = n - 1;
    for(int i = 0; i < k; i++) {
        int cnt = 0;
//        cout << a[i].size() << end;
        for(int j = 1; j < a[i].size(); j++) {
            if(a[i][j] == j)
                cnt++;
//            cout << a[i][j] << ' ' << a[i][0] << ' ' << j << endl;
        }

//        cout << cnt << endl;

        ans -= cnt;
        ans += a[i].size() - cnt - 1;
    }

    cout << ans;
}