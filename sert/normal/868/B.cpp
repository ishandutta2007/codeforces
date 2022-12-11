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
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

int dist(int a, int b) {
    return (b - a + 60) % 60;
}

int main() {
    init();
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;

    if (h == 12) h = 0;
    if (t1 == 12) t1 = 0;
    if (t2 == 12) t2 = 0;
    h *= 5;
    t1 *= 5;
    t2 *= 5;

    if (t1 == t2) {
        cout << "YES\n";
        return 0;
    }

    t2 = (t2 - t1 + 60) % 60;
    h = (h - t1 + 60) % 60;
    m = (m - t1 + 60) % 60;
    s = (s - t1 + 60) % 60;
    t1 = 0;

    int num = 0;
    if (h < t2) num++;
    if (m < t2) num++;
    if (s < t2) num++;

    if (num == 0 || num == 3)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}