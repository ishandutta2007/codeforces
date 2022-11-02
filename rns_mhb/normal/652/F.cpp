#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 300005

int n, m, s[N], d[N];
int p[N], g[2], a[N], id[N], jd[N];
vector <int> v[2];
ll t;

bool cmp(int x, int y) {
    return s[x] < s[y];
}

int get(int d, ll L, ll R) {
    if (R > 2 * m) return g[d] + get(d, L, R - m);
    if (R <= m) return lower_bound(v[d].begin(), v[d].end(), R + 1) - lower_bound(v[d].begin(), v[d].end(), L);
    return lower_bound(v[d].begin(), v[d].end(), R - m + 1) - v[d].begin() + v[d].end() - lower_bound(v[d].begin(), v[d].end(), L);
}

int main() {
	scanf("%d %d %I64d", &n, &m, &t);
    char type[2];
    f1(i, 1, n) {
    	scanf("%d %s", &s[i], type);
        if (type[0] == 'R') d[i] = 1;
        else d[i] = 0;
        g[d[i]] ++;
        v[d[i]].pb(s[i]);
        id[i] = i;
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(id + 1, id + n + 1, cmp);
    f1(i, 1, n) jd[id[i]] = i;
    ll gs = t / m % n;
    int tt = t % m;
    f1(i, 1, n) {
        a[i] = 2 * g[d[i]^1] * gs % n;
        if (d[i] == 1) a[i] += get(0, s[i], s[i] + 2ll * tt);
        else {
            ll val = s[i];
            while (val - 2 * tt <= 0) val += m;
            a[i] += get(1, val - 2 * tt, val);
        }
        a[i] %= n;
    }
    int pos, k;
    f1(i, 1, n) {
        if (d[i] == 1) pos = (s[i] + t - 1) % m + 1;
        else pos = (s[i] - t % m + m - 1) % m + 1;
        if (d[i] == 1) k = id[(jd[i] + a[i] - 1) % n + 1];
        else k = id[(jd[i] - a[i] + n - 1) % n + 1];
        p[k] = pos;
    }
    f1(i, 1, n) printf("%d ", p[i]);
	return 0;
}