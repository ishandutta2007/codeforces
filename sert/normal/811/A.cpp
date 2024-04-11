#include <bits/stdc++.h>

using namespace std;
#define TASKNAME "cactus"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)2e5 + 34;
const ll INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;

int main() {
    init();
    int a, b;
    cin >> a >> b;
    for (int i = 1; true; i++) {
        if (i % 2) a -= i;
        else b -= i;
        if (a < 0) cout << "Vladik";
        if (b < 0) cout << "Valera";
        if (min(a, b) < 0)
            return 0;
    }

    return 0;
}