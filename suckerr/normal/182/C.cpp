#include <cstdio>
#include <set>
using namespace std;

int cccccc[36000000];

int main() {
    int n, l; scanf("%d%d", &n, &l);

    int a[100000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k; scanf("%d", &k);

    long long m = -1e18;
    for (int sgn = 0; sgn <= 1; sgn++) {
        if (sgn == 1)
            for (int i = 0; i < n; i++)
                a[i] = -a[i];

        long long s = 0;
        multiset<int> ps, ns;
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0)
                s += a[i];
            else if (ps.size() < k) {
                ps.insert(a[i]);
                s += -a[i];
            } else if (k != 0 && a[i] < *(--ps.end())) {
                ps.insert(a[i]);
                s += -a[i];
                int v = *(--ps.end());
                ps.erase(ps.find(v));
                ns.insert(v);
                s -= -v; s += v;
            } else {
                ns.insert(a[i]);
                s += a[i];
            }

            int j = i-l;
            if (j >= 0)
                if (a[j] >= 0)
                    s -= a[j];
                else if (ps.find(a[j]) != ps.end()) {
                    ps.erase(ps.find(a[j]));
                    s -= -a[j];

                    if (!ns.empty()) {
                        int v = *ns.begin();
                        ns.erase(ns.find(v));
                        ps.insert(v);
                        s -= v; s += -v;
                    }
                } else {
                    ns.erase(ns.find(a[j]));
                    s -= a[j];
                }

            if (j >= -1 && s > m)
                m = s;
        }
    }

    printf("%I64d\n", m);

    return 0;
}