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


int main() {
    init();

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    while (clock() < CLOCKS_PER_SEC * 0.9 && max(a, c) < INF) {
        if (d == b) {
            cout << b;
            return 0;
        }
        if (b < d) b += a;
        else d += c;
    }

    cout << -1;

    return 0;
}