#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const ll INF = (ll)1e9 + 7;

int n, k, m, x;
set <int> s;

int main() {
    init();

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> m;
        s.clear();
        bool ok = false;
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (s.find(-x) != s.end()) ok = true;
            s.insert(x);
        }
        if (!ok) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}