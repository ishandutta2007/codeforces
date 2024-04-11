#include <bits/stdc++.h>
using namespace std;

#define N 3005

typedef pair<short, short> pss;
typedef long long ll;
int n, m;
short l[N][N], d[N][N];
int idl[N][N], idr[N][N];
char s[N][N];
int cnt;
pss q[N*N*2], tmp;
short ans[N*N*2];
vector<int> v[N<<1];
int id[N<<1];
int lvl;
int fwk[N];
ll tot;

bool cmp(int x, int y) { return q[v[lvl][x]].first < q[v[lvl][y]].first; }

void add(int x) {
    if (!x) return;
    for (int i = x; i < N; i += i & -i) fwk[i] ++;
}

int query(int x) {
    if (!x) return 0;
    int rtn = 0;
    for (int i = x; i >= 1; i -= i & -i) rtn += fwk[i];
    return rtn;
}

void calc() {
    for (lvl = 2; lvl <= n + m; lvl ++) {
        memset(fwk, 0, sizeof fwk);
        for (int i = 0; i < v[lvl].size(); i ++) id[i] = i;
        sort(id, id + v[lvl].size(), cmp);
        for (int i = 0, j = 0; i < lvl && i <= n; i ++) {
            add(l[i][lvl-i]);
            while (j < v[lvl].size() && q[v[lvl][id[j]]].first <= i) {
                ans[v[lvl][id[j]]] = q[v[lvl][id[j]]].first + 1 - query(q[v[lvl][id[j]]].second-1);
                j ++;
            }
        }
    }
}

int main() {
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i ++) gets(s[i] + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s[i][j-1] == s[i][j]) l[i][j] = l[i][j-1] + 1;
            else l[i][j] = 0;
        }
    }
    for (int i = n; i >= 1; i --) {
        for (int j = 1; j <= m; j ++) {
            if (s[i][j] == s[i+1][j-1]) d[i][j] = d[i+1][j-1] + 1;
            else d[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s[i][j] == 'z') {
                int c = min(l[i][j], d[i][j]);
                idl[i][j] = cnt;
                v[i+j].push_back(cnt);
                q[cnt++] = pss(i - 1, j);
                idr[i][j] = cnt;
                v[i+j].push_back(cnt);
                q[cnt++] = pss(i + c, j);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j >= 1; j --) {
            if (s[i][j] == s[i][j+1]) l[i][j] = l[i][j+1] + 1;
            else l[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) l[i][j] += j;
    calc();
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) if (s[i][j] == 'z') {
            tot += ans[idr[i][j]] - ans[idl[i][j]];
        }
    }
    printf("%I64d\n", tot);
    return 0;
}