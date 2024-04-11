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
typedef long long ll;
typedef long double ld;

const int N = (int)2e5 + 34;

vector <int> es[N];
int n, k;
ll num[N][6];
ll ful[N][6];
ll ans = 0;

void go(int v, int pr) {
    if (es[v].size() == 0) {
        return;
    }
    for (int i = 0; i < (int)es[v].size(); i++)
        if (es[v][i] == pr)
            swap(es[v][i], es[v].back());
    if (es[v].back() == pr)
        es[v].pop_back();

    for (auto w: es[v]) {
        go(w, v);
        for (int i = k - 1; i >= 0; i--) {
            num[w][i + 1] = num[w][i];
            ful[w][i + 1] = ful[w][i];
        }
        num[w][1]++;

        num[w][0] = num[w][k];
        ful[w][0] = ful[w][k] + num[w][k];
        for (int i = 0; i < k; i++) {
            num[v][i] += num[w][i];
            ful[v][i] += ful[w][i];
        }
    }

    for (int o = 0; o < k; o++) {
        ans += 2 * (ful[v][o] + ((o + k - 1) / k) * num[v][o]);
    }

    /*cerr << v + 1 << ":\n";
    for (int i = 0; i < k; i++) {
        cerr << "  " << i << ": " << num[v][i] << " " << ful[v][i] << "\n";
    }
    cerr << "\n";*/

    ll num1, ful1;
    for (auto w: es[v]) {
        for (int o0 = 0; o0 < k; o0++) {
            for (int o1 = 0; o1 < k; o1++) {
                num1 = num[v][o1] - num[w][o1];
                ful1 = ful[v][o1] - ful[w][o1];
                ans += ful[w][o0] * num1 + ful1 * num[w][o0];
                ans += ((o0 + o1 + k - 1) / k) * num1 * num[w][o0];
            }
        }
    }
}

int main() {
    init();
    int v1, v2;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    go(0, -1);

    printf("%I64d\n", ans / 2);

    return 0;
}