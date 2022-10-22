#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

//const bool debug_out = false;
const bool debug_out = true;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<deque<int>> pos(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int cur = 0;
    vector<int> b;
    while(cur < n) {
        b.push_back(0);
        int ncur = cur + 1;
        for(int i = 0; i < n; i++) {
            while(!pos[i].empty() && pos[i].front() < cur)
                pos[i].pop_front();
            if(!pos[i].empty()) {
                b.back()++;
                ncur = max(ncur, pos[i].front() + 1);
            } else {
                break;
            }
        }
        cur = ncur;
    }

    cout << b.size() << endl;
    for(int x : b)
        cout << x << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}