#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;


int main() {
    init();

    int q, x;
    cin >> q;
    while (q--) {
        cin >> x;
        if (x < 4 || x == 5 || x == 7 || x == 11) {
            cout << "-1\n";
            continue;
        }
        if (x == 9) {
            cout << "1\n";
            continue;
        }

        if (x % 2 == 0) {
            cout << x / 4 << "\n";
        } else {
            cout << 1 + (x - 9) / 4 << "\n";
        }
    }

    return 0;
}