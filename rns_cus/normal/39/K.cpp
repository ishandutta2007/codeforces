#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, K;
bool vis[N][N];
char s[N][N];

struct rec{
    int le, ri, dn, up;
} r[N];

bool good[N];

struct dat{
    int l, r, val;
    dat(int l = 0, int r = 0, int v = 0) : l(l), r(r), val(v) {}
    bool operator < (const dat &d) {
        return l == d.l ? r < d.r : l < d.l;
    }
};

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    for (int i = 1, k = 0; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) if (!vis[i][j] && s[i][j] == '*') {
            r[k].le = j, r[k].dn = i;
            int x = j, y = i;
            while (x <= m && s[i][x] == '*') x ++;
            while (y <= n && s[y][j] == '*') y ++;
            r[k].ri = x - 1, r[k].up = y - 1;
            for (int p = i; p < y; p ++) {
                for (int q = j; q < x; q ++) vis[p][q] = 1;
            }
            k ++;
        }
    }
    for (int i = 0; i < K; i ++) good[r[i].dn] = good[r[i].up] = 1;
    vector <int> v;
    for (int i = 1; i <= n; i ++) if (good[i]) v.push_back(i);
    int sz = v.size(); long long ans = 0;
    for (int i = 0; i < sz; i ++) for (int j = 0; j <= i; j ++) {
        vector <dat> vec;
        for (int k = 0; k < K; k ++) {
            if (r[k].up < v[j] || r[k].dn > v[i]) continue;
            if (r[k].dn < v[j] || r[k].up > v[i]) vec.push_back(dat(r[k].le, r[k].ri, 4));
            else vec.push_back(dat(r[k].le, r[k].ri, 1));
        }
        sort(vec.begin(), vec.end());
        int psz = vec.size(), pz = 0;
        for (int k = 0; k < psz; ) {
            int l = vec[k].l, r = vec[k].r, v = 0;
            while (k < psz && vec[k].l <= r) r = max(r, vec[k].r), v += vec[k].val, k ++;
            vec[pz++] = dat(l, r, v);
        }
        vec.resize(pz);
        int cnt = 0;
        for (int ii = 0, jj = 0, s = 0, c = 0; ii < pz; ii ++) {
            while (jj < pz && s + vec[jj].val <= 3) s += vec[jj].val, c += vec[jj].r - vec[jj].l, jj ++;
            s -= vec[ii].val, c -= vec[ii].r - vec[ii].l;
            if (jj > ii) {
                cnt += (vec[ii].l - (ii ? vec[ii-1].r : 0)) * ((jj < pz ? vec[jj].l : m + 1) - vec[ii].r - c);
            }
        }
        ans += 1ll * cnt * ((i < sz - 1 ? v[i+1] : n + 1) - v[i]) * (v[j] - (j ? v[j-1] : 0));
    }
    printf("%I64d\n", ans);

    return 0;
}