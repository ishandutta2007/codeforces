#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e5 + 5, INF = 0x3c3c3c3c;
int n, q, res, lazy[N*4], it[N*4], nxt[N], prv[N];
int type[N], ll[N], rr[N], xx[N];
int pos[N], ans[N];

void Enter() {
    cin >> n >> q;
}

void update(int val, int x, int y, int l = 1, int r = n, int pos = 1) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        it[pos] = lazy[pos] = val;
        return;
    }
    if (lazy[pos]) {
        lazy[pos*2] = lazy[pos*2+1] = lazy[pos];
        it[pos*2] = it[pos*2+1] = lazy[pos];
        lazy[pos] = 0;
    }
    int mid = (l+r) / 2;
    update(val, x, y, l, mid, pos*2);
    update(val, x, y, mid+1, r, pos*2+1);
    it[pos] = max(it[pos*2], it[pos*2+1]);
}

int get_max(int x, int y, int l = 1, int r = n, int pos = 1) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y || lazy[pos]) return it[pos];
    int mid = (l+r) / 2;
    return max(get_max(x, y, l, mid, pos*2), get_max(x, y, mid+1, r, pos*2+1));
}

void Process() {
    FOR(i, 1, q) {
        cin >> type[i];
        if (type[i] == 0) cin >> ll[i] >> rr[i] >> xx[i];
        else cin >> xx[i];
    }

    FORD(i, q, 1) if (type[i] == 0 && xx[i] == 0)
        update(i, ll[i], rr[i]);

    FOR(i, 1, n) {
        pos[i] = get_max(i, i);
        if (pos[i] == 0) ans[i] = -1;
    }
    nxt[n + 1] = INF;
    FORD(i, n, 1) if (ans[i] == -1) nxt[i] = i; else nxt[i] = nxt[i + 1];
    FOR(i, 1, n) if (ans[i] == -1) prv[i] = i; else prv[i] = prv[i - 1];

    FOR(i, 1, q) if (type[i] == 0 && xx[i] == 1) {
        int l = ll[i], r = rr[i];
        if (l == r) {
            if (pos[l] == 0) pos[l] = i;
            else pos[l] = min(pos[l], i);
            ans[l] = 1;
        }
        else if (nxt[l] == prv[r]) {
            int id = nxt[l];
            ans[id] = 1;
            if (pos[id] == 0) pos[id] = INF;
            pos[id] = min(pos[id], max(i, get_max(l, r)));
        }
    }

    FOR(i, 1, q) if (type[i] == 1) {
        int x = xx[i];
        if (ans[x] == -1 || pos[x] > i) cout << "N/A\n";
        else if (ans[x] == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}