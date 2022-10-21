#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 1010;

int n, d[N], c[N];

struct cmp {
    bool operator () (const int &i, const int &j) {
        return d[i] == d[j] ? i < j : d[i] < d[j];
    }
};

set<int, cmp> S;

int ask(int u) {
    printf("? %d\n", u);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    return v;
}

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        scanf("%d", &n);
        S.clear();
        for (int i = 1; i <= n; i ++) scanf("%d", &d[i]);
        for (int i = 1; i <= n; i ++) c[i] = 0, S.insert(i);
        int k = 0;
        while (!S.empty()) {
            int u = *S.rbegin();
            vector<int> x;
            x.push_back(u);
            int tmp = 0;
            for (int i = 1; ; i ++) {
                if(i == d[u] + 1) {
                    k ++;
                    break;
                }
                int v = ask(u);
                if(c[v]) {
                    tmp = c[v];
                    break;
                }
                x.push_back(v);
            }
            for (int v : x) c[v] = tmp ? tmp : k;
            for (int v : x) S.erase(v);
        }
        printf("!");
        for (int i = 1; i <= n; i ++) printf(" %d", c[i]);
        puts("");
        fflush(stdout);
    }

    return 0;
}