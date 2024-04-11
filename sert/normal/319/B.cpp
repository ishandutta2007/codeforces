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

int nx[N], pr[N];
vector <int> kilaz, tmp;

void del(int x) {
    if (pr[x] != -1)
        nx[pr[x]] = nx[x];
    if (nx[x] != -1)
        pr[nx[x]] = pr[x];
    nx[x] = pr[x] = -2;
}

int n, a[N];

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        pr[i] = i - 1;
        nx[i] = (i + 1 == n ? -1 : i + 1);
        if (i > 0 && a[i - 1] > a[i])
            kilaz.push_back(i - 1);
    }

    int it = 0;
    while (!kilaz.empty()) {
        it++;
        tmp.clear();
        for (int i = (int)kilaz.size() - 1; i >= 0; i--) {
            int kila = kilaz[i];
            del(nx[kila]);
        }
        for (int i = 0; i < (int)kilaz.size(); i++) {
            int kila = kilaz[i];
            if (nx[kila] >= 0 && a[kila] > a[nx[kila]])
                tmp.push_back(kilaz[i]);
        }
        kilaz = tmp;

        /*int p = 0;
        while (pr[p] != -1) p++;
        while (p != -1) {
            cout << p + 1 << " ";
            p = nx[p];
        }
        cout << "\n";*/
    }

    cout << it;

    return 0;
}