#include <bits/stdc++.h>
using namespace std;

#define M 1000001

int n, m;

struct dat{
    int val, id;
    dat(int val = 0, int id = 0): val(val), id(id){}
}a[M], b[M];

bool cmp(dat A, dat B) {
    if(A. val != B. val) return A. val < B.val;
    return A.id < B.id;
}

int ans[M];

int flag[M];

int Q[M];

int val[2][M];

vector<int> v[M];

int calc(int ID) {
    int x = ID / m, y = ID % m;
    return max(val[0][x], val[1][y]);
}

void update(int ID, int vv) {
    int x = ID / m, y = ID % m;
    val[0][x] = max(val[0][x], vv);
    val[1][y] = max(val[1][y], vv);
    return;
}

void bfs(int u) {
    int qh = 0;
    int tot = 0;
    Q[qh++] = u;
    flag[u] = 1;
    for(int qt = 0; qt < qh;) {
        int x = Q[qt++];
        tot = max(tot, calc(x));
        for(int i = 0; i < v[x].size(); i ++) {
            int w = v[x][i];
            if(flag[w]) continue;
            Q[qh++] = w;
            flag[w] = 1;
        }
    }
    for(int i = 0; i < qh; i ++) ans[Q[i]] = tot + 1, update(Q[i], tot + 1);
}

int change(int ID) {
    int x = ID / n , y = ID % n;
    return y * m + x;
}


int main() {
    ///freopen("C.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
        int id = (i - 1) * m + j - 1;
        scanf("%d", &a[id].val);
        a[id].id = id;
        int ID = (j - 1) * n + i - 1;
        b[ID].id = ID;
        b[ID].val = a[id].val;
    }
    sort(a, a + n * m, cmp);
    sort(b, b + n * m, cmp);
    for(int i = 0; i < n * m - 1; i ++) {
        int A = a[i].id, B = a[i + 1].id;
        if(a[i].val != a[i + 1].val) continue;
        int x = A / m, xx = B / m;
        if(x != xx) continue;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for(int i = 0; i < n * m - 1; i ++) {
        int A = b[i].id, B = b[i + 1].id;
        if(b[i].val != b[i + 1].val) continue;
        int x = A / n, xx = B / n;
        if(x != xx) continue;
        A = change(A);
        B = change(B);
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for(int i = 0; i < n * m; i ++) if(!flag[a[i].id]){
        bfs(a[i].id);
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(j == 1) printf("%d", ans[(i - 1) * m + j - 1]);
            else printf(" %d", ans[(i - 1) * m + j - 1]);
        }
        puts("");
    }
}