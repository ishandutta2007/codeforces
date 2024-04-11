// In the name of God
// I won't compile
#include <bits/stdc++.h>

using namespace std;

const int mod = 0;
const int N = 2e5 + 5, L = 19;
#define rank why_the_hell
string s[N];
int sa[N], rank[N][L], lcp_table[N], ind[N], adr[N];
pair<int, int> value[N];
int a[N], b[N], c[N];

void radix_sort(int n) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i) c[value[a[i]].second]++;
    for (int i = 1; i < N; ++i) c[i] += c[i - 1];
    for (int i = 0; i < n; ++i) b[--c[value[a[i]].second]] = a[i];
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i) c[value[b[i]].first]++;
    for (int i = 1; i < N; ++i) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i) a[--c[value[b[i]].first]] = b[i];
}

int make_suffix_array(int n) {
    for (int i = 1; i < n; ++i)
        ind[i] = ind[i - 1] + (int) s[i - 1].size();
    int m = ind[n - 1] + (int) s[n - 1].size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < (int) s[i].size(); ++j) {
            adr[ind[i] + j] = i;
            rank[ind[i] + j][0] = s[i][j] - 'a' + 1;
        }
    for (int g = 1; g < L; ++g) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < (int) s[i].size(); ++j) {
                value[ind[i] + j] = make_pair(rank[ind[i] + j][g - 1], (j + (1 << g - 1)) < s[i].size()? rank[ind[i] + j + (1 << g - 1)][g - 1]: 0);
                a[ind[i] + j] = ind[i] + j;
            }
        radix_sort(m);
        int cnt = 1;
        for (int i = 0; i < m; ++i) {
            cnt += (i > 0 && value[a[i]] != value[a[i - 1]]);
            rank[a[i]][g] = cnt;
            sa[i] = a[i];
        }
    }
    return m;
}

int lcp(int a, int b) {
    if (rank[a][L - 1] == rank[b][L - 1]) {
        return ind[adr[a]] + (int) s[adr[a]].size() - a;
    }
    int pa = adr[a];
    int pb = adr[b];
    int l = 0;
    for (int j = L - 1; j >= 0 && a < ind[pa] + (int) s[pa].size() && b < ind[pb] + s[pb].size(); --j)
        if (rank[a][j] == rank[b][j]) {
            a += 1 << j;
            b += 1 << j;
            l += 1 << j;
        }
    return l; 
}

const int S = 21 * N;
int seg[S], root[N], xl[S], xr[S], sz = 0, sm;
int build(int b = 0, int e = sm) {
    int v = sz++;
    if (b + 1 == e) {
        return v;
    }
    int m = b + e >> 1;
    xl[v] = build(b, m);
    xr[v] = build(m, e);
    return v;
}

int last[N];

int update(int pos, int x, int id, int b = 0, int e = sm) {
    int v = sz++;
    seg[v] = seg[id];
    xl[v] = xl[id];
    xr[v] = xr[id];
    if (b + 1 == e) {
        seg[v] += x;
        return v;
    }
    int m = b + e >> 1;
    if (pos < m)
        xl[v] = update(pos, x, xl[id], b, m);
    else
        xr[v] = update(pos, x, xr[id], m, e);
    seg[v] = seg[xl[v]] + seg[xr[v]];
    return v;
}

int query(int i, int j, int v, int b = 0, int e = sm) {
    if (i >= e || b >= j)
        return 0;
    if (i <= b && e <= j)
        return seg[v];
    int m = b + e >> 1;
    return query(i, j, xl[v], b, m) + query(i, j, xr[v], m, e);
}

int rmq[L][N], width[N];

int get_min(int l, int r) {
    int w = width[r - l];
    return min(rmq[w][l], rmq[w][r - (1 << w)]);
}

int get_lcp(int l, int r) {
    if (l > r)
        swap(l, r);
    return get_min(l, r);
}
long long res[N];
int main() {
    ios_base :: sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    int m = make_suffix_array(n);
    sm = m;
    for (int i = 0; i < m - 1; ++i) {
        lcp_table[i] = lcp(sa[i], sa[i + 1]);
    }
    root[0] = build();
    memset(last, -1, sizeof last);
    for (int i = 0; i < m; ++i) {
        int x = root[i];
        int p = adr[sa[i]];
        if (last[p] >= 0) {
            x = update(last[p], -1, x);
        }
        last[p] = i;
        root[i + 1] = update(i, 1, x);
    }
    width[1] = 0;
    for (int i = 2; i < N; ++i)
        width[i] = width[i >> 1] + 1;
    for (int i = 0; i < m - 1; ++i)
        rmq[0][i] = lcp_table[i];
    for (int j = 1; j < L; ++j)
        for (int i = 0; i < m - 1; ++i)
            if (i + (1 << j - 1) < m - 1) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << j - 1)]);
            } else {
                rmq[j][i] = rmq[j - 1][i];
            }
    for (int j = 0; j < m; ++j) {
        int x = sa[j];
        int sz = ind[adr[x]] + (int) s[adr[x]].size() - x;
        int bl = 0, br = sz + 1;
        while (bl < br - 1) {
            int l = j, r = j;
            int bm = bl + br >> 1;
            int bs = j, be = m;
            while (bs < be - 1) {
                int bmid = bs + be >> 1;
                if (get_lcp(j, bmid) >= bm)
                    bs = bmid;
                else
                    be = bmid;
            }
            r = be;
            bs = -1, be = j;
            while (bs < be - 1) {
                int bmid = bs + be >> 1;
                if (get_lcp(j, bmid) >= bm)
                    be = bmid;
                else
                    bs = bmid;
            }
            l = be;
            if (query(l, r, root[r]) >= k)
                bl = bm;
            else
                br = bm;
        }
   //     cout << " hi " << j << ' ' << bl << ' ' << x << ' ' << adr[x] << endl;
        res[adr[x]] += bl;
    }
    for (int j = 0; j < n; ++j)
        cout << res[j] << ' ';
}