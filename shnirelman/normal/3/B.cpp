#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 2e9;

mt19937 rnd(time(0));


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pii> a, b;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if(x == 1) {
            a.emplace_back(y, i);
        } else {
            b.emplace_back(y, i);
        }
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int res = 0, ans = 0;
    int cur = 0;
    int j = 0;
    for(int i = 0; i <= b.size(); i++) {
        while(j < a.size() && j + i * 2 < m) {
            cur += a[j].f;
            j++;
        }

        while(j > 0 && j + i * 2 > m) {
            j--;
            cur -= a[j].f;
        }

        if(res < cur) {
            res = cur;
            ans = i;
        }

        if(i < b.size() && i * 2 + 2 <= m) {
            cur += b[i].f;
        } else
            break;
    }

    cout << res << endl;
    for(int i = 0; i < ans; i++)
        cout << b[i].s + 1 << ' ';

    for(int i = 0; i < a.size() && i + ans * 2 < m; i++) {
        cout << a[i].s + 1 << ' ';
    }
}