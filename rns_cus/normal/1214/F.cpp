#include <bits/stdc++.h>
using namespace std;

#define N 800800

int n, m, a[N], b[N], nxt[N][2], nt[N], c[N], prv[N];
typedef pair <int, int> pii;
vector <pii> vec;
typedef long long ll;
ll sum[N], s[N][2];
int ida[N], idb[N], id[N];

bool vis[N];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), vec.push_back(pii(a[i], i));
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), vec.push_back(pii(b[i], i + n));
    sort(vec.begin(), vec.end()); vec.resize(4 * n);
    for (int i = 0; i < 2 * n; i ++) vec[i+2*n] = vec[i], vec[i+2*n].first += m;
    for (int i = 0; i < 4 * n; i ++) if (vec[i].second > n) c[i] = 1; else c[i] = -1;
    nxt[4*n-1][0] = nxt[4*n-1][1] = nt[4*n-1] = 4 * n;
    for (int i = 4 * n - 2; i >= 0; i --) {
        nt[i] = 4 * n;
        if (c[i+1] != c[i]) nt[i] = i + 1, sum[i] = vec[i+1].first - vec[i].first;
        else {
            int j;
            if (c[i] < 0) j = nxt[i+1][1], sum[i] = s[i+1][1];
            else j = nxt[i+1][0], sum[i] = s[i+1][0];
            if (j < 4 * n) nt[i] = j, sum[i] += vec[j].first - vec[i].first;
            else sum[i] = 0, nt[i] = 4 * n;
        }
        int j = nt[i] + 1;
        if (j >= 4 * n) nxt[i][0] = nxt[i][1] = 4 * n;
        else {
            if (c[j] < 0) nxt[i][0] = j, nxt[i][1] = nxt[j][1], s[i][0] = sum[i], s[i][1] = sum[i] + s[j][1];
            else nxt[i][1] = j, nxt[i][0] = nxt[j][0], s[i][1] = sum[i], s[i][0] = sum[i] + s[j][0];
            if (nxt[i][0] == 4 * n) s[i][0] = 0;
            if (nxt[i][1] == 4 * n) s[i][1] = 0;
        }
//        cout << i << ' ' << nt[i] << ' ' << sum[i] << endl;
    }
    ll rlt = 1e18;
    int st = -1;
    for (int i = 0; i < 2 * n; i ++) {
        if (vis[i]) continue;
        ll ss = 0; int j;
        for (j = i; j != i + 2 * n; j = nt[j] + 1) {
            ss += sum[j], vis[j] = 1;
//            if (i == 4) cout << "here " << j << endl;
        }
        while (j < 4 * n) vis[j] = 1, j = nt[j] + 1;
        if (rlt > ss) rlt = ss, st = i;
    }
//    cout << st << endl;
    assert(st >= 0);
    int aa = 0, bb = 0;
    for (int i = st; i < st + 2 * n; i ++) {
        if (vec[i].second <= n) ida[++aa] = vec[i].second;
        else idb[++bb] = vec[i].second - n;
    }
    for (int i = 1; i <= n; i ++) id[ida[i]] = idb[i];
    printf("%I64d\n", rlt);
    for (int i = 1; i <= n; i ++) printf("%d ", id[i]);

}