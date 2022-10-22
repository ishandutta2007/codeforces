#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<bool> c(m, false);
    int col = 0;

    int cnt = 0;
    vector<int> sum(m, 0);
    for(int ind = 0; ind < n * m; ind++) {
        if(s[ind] == '1' && !c[ind % m]) {
            col++;
            c[ind % m] = true;
        }

        if(s[ind] == '0')
            cnt++;
        else
            cnt = 0;

        if(cnt >= m || cnt == ind + 1) {
            sum[ind % m]++;
        }
//        cout << "cnt = " << cnt << " sum = " << sum[ind % m] << endl;
//        cout << "(" << col << ", " << (ind + m) / m - sum[ind % m] << ") " << endl;
        cout << col + (ind + m) / m - sum[ind % m] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}