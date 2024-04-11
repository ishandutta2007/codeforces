#include <bits/stdc++.h>

using namespace std;

char s[1 << 13];

struct dsu {
    vector<int> p, w;
    dsu() {}
    dsu(int n) : p(n), w(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int getp(int x) {
        if (p[x] != x)
            p[x] = getp(p[x]);
        return p[x];
    }
    void merge(int x, int y) {
        if (w[x] < w[y])
            swap(x, y);
        p[y] = x;
        w[x] += w[y];
    }
};

int main(){
#ifdef FLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, t, ans = 0, l, nn = 0, x;
    scanf("%d%d", &n, &m);
    vector<int> a(m + 1), num(m + 1);
    for (int i = 0; i < n; i++) {
        scanf("%s", &s);
        for (int j = 0; j < m / 4; j++) {
            t = s[j] >= 'A' ? s[j] - 'A' + 10 : s[j] - '0';
            for (int k = 3; k >= 0; k--, t /= 2)
                a[j * 4 + k] = t % 2;
        }
        l = -1;
        vector<int> cn;
        dsu ds(2 * m + 1);
        for (int j = 0; j <= m; j++) {
            if (a[j]) {
                if (num[j])
                    cn.push_back(num[j]);
                continue;
            }
            if (j == 0 || !a[j - 1]) {
                l = j;
                num[j] = 0;
                continue;
            }
            if (cn.empty()) {
                ans++;
                nn++;
                for (int k = l + 1; k < j; k++)
                    num[k] = nn;
                l = j;
                num[j] = 0;
                continue;
            }
            for (int k : cn) {
                t = ds.getp(cn[0]);
                x = ds.getp(k);
                if (t != x) {
                    ds.merge(x, t);
                    ans--;
                }
            }
            for (int k = l + 1; k < j; k++)
                num[k] = t;
            num[j] = 0;
            l = j;
            cn.clear();
        }
        for (int i = 0; i < m; i++)
            num[i] = ds.getp(num[i]);
        vector<int> cnt(2 * m + 1), tn(2 * m + 1);
        for (int j : num)
            cnt[j]++;
        for (int j = 1; j < 2 * m + 1; j++) {
            if (cnt[j])
                tn[j] = tn[j - 1] + 1;
            else
                tn[j] = tn[j - 1];
        }
        for (int i = 0; i < m; i++)
            num[i] = tn[num[i]];
        nn = tn[2 * m];
    }
    printf("%d\n", ans);
}