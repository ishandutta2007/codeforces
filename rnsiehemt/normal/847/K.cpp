#include <bits/stdc++.h>

int n, a, b, k, f, nextid = 1, cost[605][605], x[305], y[305];
char ss[25], tt[25];
std::string s, t;
std::map<std::string, int> m;
std::vector<int> allc;

int getid(std::string s) {
    if (m[s] == 0) {
        m[s] = nextid++;
    }
    return m[s];
}

int main() {
    scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
    for (int i = 0; i < n; i++) {
        scanf(" %s %s", ss, tt);
        s = ss;
        t = tt;
        x[i] = getid(s);
        y[i] = getid(t);
        int c = 0;
        if (i && x[i] == y[i-1]) {
            c = b;
        } else {
            c = a;
        }
        cost[std::min(x[i], y[i])][std::max(x[i], y[i])] += c;
    }
    for (int i = 1; i < nextid; i++) {
        for (int j = i; j < nextid; j++) {
            allc.push_back(cost[i][j]);
        }
    }
    std::sort(allc.begin(), allc.end());
    std::reverse(allc.begin(), allc.end());
    int ans = 0;
    for (int i = 0; i < int(allc.size()); i++) {
        if (i < k && f < allc[i]) {
            ans += f;
        } else {
            ans += allc[i];
        }
    }
    printf("%d\n", ans);
}