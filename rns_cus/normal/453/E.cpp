#include <bits/stdc++.h>
using namespace std;
#define N 401000
typedef long long ll;
ll Sum[N][2], Sum1[N][2];
int Stt[N];
int n;
struct dat{
    int ti;
    ll sum, sum1;
    dat(int ti = 0, ll sum = 0, ll sum1 = 0):ti(ti), sum(sum), sum1(sum1){}
};

bool operator < (dat a, dat b) {
    return a.ti < b.ti;
}

vector<dat> v[N][2];
int St[N], Lim[N], r[N], Id[N], mx[N],mn[N], re[N], vis[N], add[N];
bool cmp(int i, int j) {
    return re[i] < re[j];
}
#define inf 1000000000
void doit(int st, int en, int id, int di) {
    v[id][di].clear();
    int cnt = 0;
    for(int i = st; i <= en; i ++) {
        if(r[i] == 0) {
            re[i] = inf;
            continue;
        }

        if(St[i] == Lim[i]) re[i] = 0;
        else {
            re[i] = (Lim[i] -St[i] - 1) / r[i] + 1;
        }
    }
    for(int i = st; i <= en; i ++) Id[i] = i;
    sort(Id + st, Id + en + 1, cmp);
    int stpos = st;
    ll sum = 0;
    ll sum1 = 0;
    for(int i = st; i <= en; i ++) sum += St[i];
    for(int i = st; i <= en; i ++) sum1 += r[i];
    Sum[id][di] = sum;
    Sum1[id][di] = sum1;
    sum += Lim[Id[st]] - St[Id[st]];
    sum1 -= r[Id[st]];
    for(int i = st + 1; i <= en; i ++) {
        int j = Id[i];
        int k = Id[stpos];
        if(re[j] != re[k]) {
            v[id][di].push_back(dat(re[k], sum, sum1));
            sum1 -= r[j];
            sum += Lim[j] - St[j];
            stpos = i;
        } else {
            sum1 -= r[j];
            sum += Lim[j] - St[j];
        }
    }
    v[id][di].push_back(dat(re[Id[stpos]], sum, sum1));
}



void build(int st, int en, int id) {
    mx[id] = mn[id] = vis[id] = 0;
    for(int i = st; i <= en; i ++) St[i] = Stt[i];
    doit(st, en, id, 0);
    for(int i = st; i <= en; i ++) St[i] = 0;
    doit(st, en, id, 1);
    if(st == en) return ;
    int mid = (st + en) >> 1;
    build(st, mid, id * 2);
    build(mid + 1, en, id * 2 + 1);
}

void push_down(int id) {
    int l = id * 2;
    int r = id * 2 + 1;
    if(vis[id]) {
        vis[l] = vis[r] = 1;
    }
    if(add[id]) {
        mx[l] += add[id];
        mn[l] += add[id];
        add[l] += add[id];
        mx[r] += add[id];
        mn[r] += add[id];
        add[r] += add[id];
        add[id] = 0;
    }
}

void push_up(int id) {
    int l = id * 2;
    int r = id * 2 + 1;
    mx[id] = max(mx[l], mx[r]);
    mn[id] = min(mn[l], mn[r]);
    if(vis[l] && vis[r]) vis[id] = 1;
}

ll Calc(int st, int en, int id, int di, int ti) {
    dat a = dat(ti, 0, 0);
    int k = lower_bound(v[id][di].begin(), v[id][di].end(), a) - v[id][di].begin();

    if(k != v[id][di].size() && v[id][di][k].ti == ti) {
        return v[id][di][k].sum + v[id][di][k].sum1 * ti;
    }
    if(k == 0) {
        return Sum[id][di] + Sum1[id][di] * ti;
    }
    k --;
    return v[id][di][k].sum + v[id][di][k].sum1 * ti;
}

ll calc(int l, int r, int st, int en, int id, int ti) {
    if(l > en || r < st) return 0;
    if(l <= st && en <= r && mx[id] == mn[id]) {
        return Calc(st, en, id, vis[id], ti + mx[id]);
    }
    push_down(id);
    int mid = (st + en) >> 1;
    return calc(l, r, st, mid, id * 2, ti) + calc(l, r, mid + 1, en, id * 2 + 1, ti);
}

void chan(int l, int r, int st, int en, int id) {
    if(l > en || r < st) return ;
    if(l <= st && en <= r && mx[id] == mn[id]) {
        vis[id] = 1;
        add[id] -= mx[id];
        mx[id] = mn[id] = 0;
        return ;
    }
    push_down(id);
    int mid = (st + en) >> 1;
    chan(l, r, st, mid, id * 2);
    chan(l, r, mid + 1, en, id * 2 + 1);
    push_up(id);
}

void Chan(int L, int R, int ti) {
    add[1] += ti;
    chan(L, R, 1, n, 1);
}
int main() {
    int m, L, R, ti;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &Stt[i], &Lim[i], &r[i]);
    }
    build(1, n, 1);
    int va = 0;
    for(scanf("%d", &m); m --;) {
        scanf("%d%d%d", &ti, &L, &R);
        ll x = calc(L, R, 1, n, 1, ti - va);
        printf("%I64d\n", x);
        Chan(L, R, ti - va);
        va = ti;
    }
}