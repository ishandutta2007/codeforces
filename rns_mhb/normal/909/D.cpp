#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define N 1000010
typedef pair <char, int> pci;


char c, s[N];
int i, te, p, len, ans = 0, num[N];
bool vis[N];
vector <pci> se(N), t(N);


int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    gets(s);
    len = strlen(s);
    se[0] = mp(s[0], 1);
    for (i = p = 0; i < len - 1; i ++) {
        if (s[i] == s[i+1]) se[p].second ++;
        else se[++p] = mp(s[i+1], 1);
    }
    while (1) {
        if (p <= 0) break;
        te = se[0].second;
        for (i = 1; i < p; i ++) te = min(te, (se[i].second + 1) / 2);
        te = min(te, se[p].second);
        se[0].second -= te, se[p].second -= te, ans += te;
        for (i = 1; i < p; i ++) se[i].second = max(0, se[i].second - 2 * te);
        for (i = 0; i <= p && !se[i].second; i ++);
        for (te = -1, c = 0; i <= p; i ++) {
            if (c == se[i].first || se[i].second == 0) t[te].second += se[i].second;
            else t[++te] = se[i], c = se[i].first;
        }
        p = te;
        for (i = 0; i <= p; i ++) se[i] = t[i];
    }
    printf("%d\n", ans);
    return 0;
}