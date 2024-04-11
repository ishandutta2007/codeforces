#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 200 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<string>> a(4, vector<string>(n));
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < n; i++)
            cin >> a[k][i];
    }

    vector<pii> b(4, make_pair(0, 0));
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[k][i][j] - '0' ==  (i + j) % 2)
                    b[k].f++;
                else
                    b[k].s++;
            }
        }
    }

    vector<int> p = {0, 1, 2, 3};
    int ans = INF;
    do {
        ans = min(ans, b[p[0]].f + b[p[1]].f + b[p[2]].s + b[p[3]].s);
    } while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
}