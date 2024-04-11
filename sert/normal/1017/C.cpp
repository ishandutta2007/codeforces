#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;

int f(int n, int x) {
    return x + (n + x - 1) / x;
}

void solve() {
    int n;
    cin >> n;
    int bst = -1, score = n * 2 + 1;

    for (int i = 1; i <= n; i++) {
        int cur = f(n, i);
        if (cur < score) {
            bst = i;
            score = cur;
        }
    }

    int it = (n + bst - 1) / bst;
    for (int i = 0; i < it; i++) {
        for (int j = i * bst + bst; j > i * bst; j--) {
            if (j <= n) {
                cout << j << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
#endif

	//int t; scanf("%d", &t); while (t--)
	//int t; cin >> t; while (t--)
	solve();
}