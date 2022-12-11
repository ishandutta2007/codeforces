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
bool u[N];
int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int msk = 0;
        int x;
        for (int j = 0; j < k; j++) {
            cin >> x;
            msk = msk * 2 + x;
        }
        u[msk] = true;
        //cerr << msk << "\n";
    }

    int a[34];
    for (int msk = 1; msk < (1 << (1 << k)); msk++) {
        int tasks = __builtin_popcount(msk);
        for (int i = 0; i < k; i++)
            a[i] = 0;

        bool fail = false;
        for (int m = 0; m < (1 << k); m++) {
            if ((msk & (1 << m)) == 0) continue;
            if (!u[m]) fail = true;

            for (int i = 0; i < k; i++)
                if (m & (1 << i))
                    a[i]++;
        }

        for (int i = 0; i < k; i++)
            if (a[i] * 2 > tasks)
                fail = true;

        if (!fail) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}