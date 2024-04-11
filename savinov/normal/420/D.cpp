#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000001;

int sum[4 * MAXN];
int val[4 * MAXN];

int po, pov;

void get(int v, int tl, int tr, int s) {
    if (tl == tr) {
        po = tl;
        pov = v;
        return;
    }
    int tm = (tl + tr) / 2;
    if (sum[v + v] >= s) {
        return get(v + v, tl, tm, s);
    } else {
        return get(v + v + 1, tm + 1, tr, s - sum[v + v]);
    }
}

void update(int v, int tl, int tr, int pos, int va, int co) {
    if (tl == tr) {
        sum[v] = va;
        val[v] = co;
        return;
    }
    int tm = (tl + tr) / 2;

    if (pos <= tm) {
        update(v + v, tl, tm, pos, va, co);
    } else {
        update(v + v + 1, tm + 1, tr, pos, va, co);
    }
    sum[v] = sum[v + v] + sum[v + v + 1];
}

int values[MAXN];

char used[MAXN];

char used2[MAXN];

void go(int v, int tl, int tr) {
    if (tl == tr) {
        values[tl] = val[v];
        return;
    }

    int tm = (tl + tr) / 2;

    go(v + v, tl, tm);
    go(v + v + 1, tm + 1, tr);

}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(val, 255, sizeof(val));
    vector <pair<int, int> > ft;
    for (int i = m + 1; i <= m + n; ++i) {
        update(1, 1, n + m, i, 1, -1);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        used[x] = 1;
        get(1, 1, n + m, y);

        if (val[pov] != -1 && val[pov] != x) {
            puts("-1");
            return 0;
        }
        ft.push_back(make_pair(po, m - i));

        update(1, 1, n + m, m - i, 1, x);
        update(1, 1, n + m, po, 0, -1);
    }
    go(1, 1, n + m);
    for (int i = (int)ft.size() - 1; i >= 0; --i) {
        swap(values[ft[i].first], values[ft[i].second]);
    }

    int pointer = 1;


    for (int i = 1; i <= n; ++i) {
        while (used[pointer]) {
            ++pointer;
        }
        if (values[i + m] == -1) {
            values[i + m] = pointer++;
        }
        if (used2[values[i + m]]) {
            puts("-1");
            return 0;
        }
        used2[values[i + m]] = 1;

    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) printf(" ");
        printf("%d", values[i + m]);
    }

    printf("\n");
    return 0;
}