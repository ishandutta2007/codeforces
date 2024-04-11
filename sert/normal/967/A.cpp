#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;
const int H = 60;

void solve() {
    int n, s, h, m;
    vector<int> a;
    cin >> n >> s;
    a.push_back(-s - 1);
    for (int i = 0; i < n; i++) {
        cin >> h >> m;
        a.push_back(h * 60 + m);
    }
    a.push_back(a.back() + s * 3 + 34);
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] - a[i - 1] >= s * 2 + 2) {
            int t = a[i - 1] + s + 1;
            cout << t / 60 << " " << t % 60 << "\n";
            return;
        }
    }
}

int main() {
    init();
	solve();
	//solve();
	//solve();
	//solve();
    return 0;
}