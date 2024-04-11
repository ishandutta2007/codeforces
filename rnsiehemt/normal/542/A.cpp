#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

const ll inf = 1000*1000*1000+3;

int N, M;
ll l[200005];
ll r[200005];
ll a[200005];
ll b[200005];
ll c[200005];
int idx[200005];
int jdx[200005];
ll best[200005];
int besti[200005];
ll rmax[8000*1000 + 5];
int ridx[8000*1000 + 5];
int Nodes = 1;
int lc[8000*1000 + 5];
int rc[8000*1000 + 5];

bool cmp0(const int &x, const int &y) { return l[x] < l[y]; }
bool cmp1(const int &x, const int &y) { return r[x] > r[y]; }
bool cmp2(const int &x, const int &y) { return a[x] < a[y]; }
bool cmp3(const int &x, const int &y) { return b[x] > b[y]; }
bool cmp911(const int &x, const int &y) { return r[x] < r[y]; }
bool cmp420(const int &x, const int &y) { return b[x] < b[y]; }

void update(int n, int nl, int nr, int qi, ll qv, int qvi) {
    if (qv > rmax[n]) { rmax[n] = qv; ridx[n] = qvi; }
    if (nl != nr-1) {
        if (qi < (nl+nr)/2) {
            if (!lc[n]) lc[n] = Nodes++;
            update(lc[n], nl, (nl+nr)/2, qi, qv, qvi);
        } else {
            if (!rc[n]) rc[n] = Nodes++;
            update(rc[n], (nl+nr)/2, nr, qi, qv, qvi);
        }
    }
}


std::pair<ll, int> query(int n, int nl, int nr, int ql, int qr) {
    if (nr <= ql || qr <= nl) return std::make_pair(0ll, -1);
    else if (ql <= nl && nr <= qr) return std::make_pair(rmax[n], ridx[n]);
    else return std::max((lc[n] ? query(lc[n], nl, (nl+nr)/2, ql, qr) : std::make_pair(0ll, -1)),
        (rc[n] ? query(rc[n], (nl+nr)/2, nr, ql, qr) : std::make_pair(0ll, -1)));
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%lld%lld", &l[i], &r[i]);
    for (int j = 0; j < M; j++) scanf("%lld%lld%lld", &a[j], &b[j], &c[j]);

    for (int i = 0; i < N; i++) idx[i] = i;
    for (int j = 0; j < M; j++) jdx[j] = j;

    std::sort(idx, idx+N, cmp0);
    std::sort(jdx, jdx+M, cmp2);
    ll max = -1; int maxi = -1;
    int i = 0;
    for (int j = 0; j < M; j++) {
        while (i < N && l[idx[i]] <= a[jdx[j]]) {
            if (r[idx[i]] > max) { max = r[idx[i]]; maxi = idx[i]; }
            i++;
        }
        if (max > a[jdx[j]] && max-a[jdx[j]] > best[jdx[j]]) { best[jdx[j]] = max-a[jdx[j]]; besti[jdx[j]] = maxi; }
    }
    
    std::sort(idx, idx+N, cmp1);
    std::sort(jdx, jdx+M, cmp3);
    i = 0;
    //for (int i = 0; i < N; i++) printf("%d%c", idx[i], " \n"[i == N-1]);
    //for (int j = 0; j < M; j++) printf("%d%c", jdx[j], " \n"[j == M-1]);
    ll min = inf; int mini = -1;
    for (int j = 0; j < M; j++) {
        while (i < N && r[idx[i]] >= b[jdx[j]]) {
            if (l[idx[i]] < min) { min = l[idx[i]]; mini = idx[i]; }
            i++;
        }
        //printf("j = %d, i = %d, min = %lld\n", j, i, min);
        if (min < b[jdx[j]] && b[jdx[j]]-min > best[jdx[j]]) { best[jdx[j]] = b[jdx[j]]-min; besti[jdx[j]] = mini; }
    }
    
    std::sort(idx, idx+N, cmp911);
    std::sort(jdx, jdx+M, cmp420);
    i = 0;    
    for (int j = 0; j < M; j++) {
        while (i < N && r[idx[i]] <= b[jdx[j]]) {
            update(0, 0, 1000*1000*1000+1, l[idx[i]], r[idx[i]]-l[idx[i]], idx[i]);
            i++;
        }
        std::pair<ll, int> aoeu = query(0, 0, 1000*1000*1000+1, a[jdx[j]], b[jdx[j]]);
        if (aoeu.first > best[jdx[j]]) { best[jdx[j]] = aoeu.first; besti[jdx[j]] = aoeu.second; }
    }

    for (int j = 0; j < M; j++) best[j] = std::min(best[j], b[j]-a[j]);
    //for (int j = 0; j < M; j++) printf("best for %d is %lld with %d\n", j, best[j], besti[j]);
    ll ans = 0ll; int ansj = -1;
    for (int j = 0; j < M; j++) if (best[j]*c[j] > ans) { ans = best[j]*c[j]; ansj = j; }
    if (ans) printf("%lld\n%d %d\n", ans, besti[ansj]+1, ansj+1);
    else printf("%lld\n", ans);
}