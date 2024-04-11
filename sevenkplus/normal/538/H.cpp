#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 100010
#define INF 1000000007

int tl, tr;
int n, m, lw0[N], rw0[N], co[N];
vector<int> c1, c2;
int lw[N], rw[N], zw[N]; int c;
vector<int> A[N]; int v[N];
bool w[N];
int l1, r1, l2, r2;

void EXIT() {
    puts ("IMPOSSIBLE");
    exit(0);
}

void ff(int x, int y) {
    v[x] = y;
    if (y == 1) {
        c1.pb(x);
        l1 = max(l1, lw0[x]);
        r1 = min(r1, rw0[x]);
    } else {
        c2.pb(x);
        l2 = max(l2, lw0[x]);
        r2 = min(r2, rw0[x]);
    }
    for (vector<int>::iterator i = A[x].begin(); i != A[x].end(); i ++) {
        if (!v[*i]) ff(*i, 3-y);
        else if (v[*i] != 3-y) EXIT();
    }
}

multiset<int> L0, R0, L1, R1;
int p[N*2], L;

int ht(int x) {
    if (x >= 0) return lw[x];
    else return rw[-x-1]+1;
}

bool cmp(int x, int y) {
    return ht(x) < ht(y);
}

void add0(int i) {L0.insert(lw[i]); R0.insert(rw[i]);}
void del0(int i) {L0.erase(L0.find(lw[i])); R0.erase(R0.find(rw[i]));}
void add1(int i) {L1.insert(lw[i]); R1.insert(rw[i]);}
void del1(int i) {L1.erase(L1.find(lw[i])); R1.erase(R1.find(rw[i]));}

#define chk(x, y) if(CHK(l0, r0, l1, r1, x, y)) return mp(x,y)

inline bool CHK(int l0, int r0, int l1, int r1, int x, int y) {
    if (x < l0 || x > r0 || y < l1 || y > r1) return false;
    if (x+y < tl || x+y > tr) return false;
    return true;
}

const PII ER = mp(-1,-1);

PII chk0() {
    int l0 = 0, r0 = INF;
    if (!L0.empty()) l0 = *L0.rbegin();
    if (!R0.empty()) r0 = *R0.begin();
    int l1 = 0, r1 = INF;
    if (!L1.empty()) l1 = *L1.rbegin();
    if (!R1.empty()) r1 = *R1.begin();
    // cout << l0 << " " << r0 << " " << l1 << " " << r1 << endl;
    chk(l0, l1);
    chk(l0, r1);
    chk(l0, tl-l0);
    chk(l0, tr-l0);
    chk(r0, l1);
    chk(r0, r1);
    chk(r0, tl-r0);
    chk(r0, tr-r0);
    chk(l0, l1);
    chk(r0, l1);
    chk(tl-l1, l1);
    chk(tr-l1, l1);
    chk(l0, r1);
    chk(r0, r1);
    chk(tl-r1, r1);
    chk(tr-r1, r1);
    return ER;
}

int np = 0;

int sv[N];

int main () {
    cin >> tl >> tr;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> lw0[i] >> rw0[i];
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        -- x; -- y;
        A[x].pb(y);
        A[y].pb(x);
    }
    memset(zw, -1, sizeof zw);
    for (int i = 0; i < n; i ++) if (!v[i]) {
        l1 = 0; r1 = INF;
        l2 = 0; r2 = INF;
        c1.clear();
        c2.clear();
        ff(i, 1);
        if (l1 > r1) EXIT();
        if (l2 > r2) EXIT();
        if (!c1.empty()) {
            lw[c] = l1; rw[c] = r1; c ++;
            for (int i = 0; i < (int) c1.size(); i ++)
                co[c1[i]] = c-1;
        }
        if (!c2.empty()) {
            lw[c] = l2; rw[c] = r2; c ++;
            for (int i = 0; i < (int) c2.size(); i ++)
                co[c2[i]] = c-1;
        }
        if (!c1.empty() && !c2.empty()) {
            zw[c-2] = c-1; zw[c-1] = c-2;
            np ++;
        }
    }
    for (int i = 0; i < c; i ++) {
        p[L++] = i;
        p[L++] = -i-1;
    }
    sort(p, p+L, cmp);
    for (int i = 0; i < c; i ++) add1(i);
    PII S = ER;
    if (!np) S = chk0();
    for (int i = 0; i < L-1 && S == ER; i ++) {
        if (p[i] < 0) break;
        bool F = true;
        if (zw[p[i]] != -1 && !w[zw[p[i]]]) np--;
        if (zw[p[i]] != -1 && w[zw[p[i]]]) F = false;
        if (F) {
            del1(p[i]);
            add0(p[i]);
            w[p[i]] = 1;
        } else {
            if (rw[p[i]] < rw[zw[p[i]]]) {
                del1(p[i]);
                add0(p[i]);
                del0(zw[p[i]]);
                add1(zw[p[i]]);
                w[p[i]] = 1;
                w[zw[p[i]]] = 0;
            }
        }
        int t0 = ht(p[i]);
        int t1 = ht(p[i+1]);
        if (t0 == t1) continue;
        if (np) continue;
        S = chk0();
    }
    if (S != ER) {
        puts ("POSSIBLE");
        printf ("%d %d\n", S.fi, S.se);
        memset(w, 0, sizeof w);
        for (int i = 0; i < c; i ++) if (!w[i])
            if (zw[i] == -1) {
                w[i] = 1;
                if (lw[i] <= S.fi && S.fi <= rw[i]) sv[i] = 0;
                else {
                    assert(lw[i] <= S.se && S.se <= rw[i]);
                    sv[i] = 1;
                }
            } else {
                w[i] = 1;
                w[zw[i]] = 1;
                if (lw[i] <= S.fi && S.fi <= rw[i] && lw[zw[i]] <= S.se && S.se <= rw[zw[i]]) {
                    sv[i] = 0; sv[zw[i]] = 1;
                } else {
                    assert (lw[i] <= S.se && S.se <= rw[i] && lw[zw[i]] <= S.fi && S.fi <= rw[zw[i]]);
                    sv[i] = 1; sv[zw[i]] = 0;
                }
            }
        for (int i = 0; i < n; i ++) {
            if (sv[co[i]] == 0) putchar('1'); else putchar('2');
        }
        puts ("");
    }
    else EXIT();
    return 0; 
}