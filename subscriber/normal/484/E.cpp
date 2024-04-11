#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k;
int h[N], A[N], B[N], mid[N];
int l[N], r[N], w[N];

int val[888888], pref[888888], suf[888888];

struct ret {
    int val, pref, suf;
    ret() {
    }
    ret(int val, int pref, int suf): val(val), pref(pref), suf(suf) {
    }
};

void init(int pos, int l, int r) {
    val[pos] = 0;
    pref[pos] = suf[pos] = 0;
    if (l == r) return;

    init(pos + pos, l, (l + r) / 2);
    init(pos + pos + 1, (l + r) / 2 + 1, r);
}

void add(int pos, int l, int r, int x) {
    if (x < l || x > r) return;
    if (l == r) {
        val[pos] = 1;
        pref[pos] = 1;
        suf[pos] = 1;
        return;
    }
    add(pos + pos, l, (l + r) / 2, x);
    add(pos + pos + 1, (l + r) / 2 + 1, r, x);

    val[pos] = max( max(val[pos + pos], val[pos + pos + 1]), suf[pos + pos] + pref[pos + pos + 1]);
    int s1 = (l + r) / 2 - l + 1;

    int s2 = r - (l + r) / 2;
    
    pref[pos] = pref[pos + pos];
    if (val[pos + pos] == s1) pref[pos] = s1 + pref[pos + pos + 1];

    suf[pos] = suf[pos + pos + 1];
    if (val[pos + pos + 1] == s2) suf[pos] = s2 + suf[pos + pos];
}

ret fin(int pos, int l, int r, int ll, int rr) {
    ll = max(ll, l);
    rr = min(rr, r);
    if (ll > rr) return ret(0, 0, 0);

    if (l == ll && r == rr) return ret(val[pos], pref[pos], suf[pos]);

    ret q1 = fin(pos + pos, l, (l + r) / 2, ll, rr);
    ret q2 = fin(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr);

    int s1 = max(min(rr, (l + r) / 2) - l + 1, 0);
    int s2 = max(rr - max(ll, (l + r) / 2 + 1) + 1, 0);

    int val = max(q1.val, q2.val);
    val = max(val, q1.suf + q2.pref);

    int pref = q1.pref;
    if (q1.val == s1) pref = s1 + q2.pref;
    int suf = q2.suf;
    if (q2.val == s2) suf = s2 + q1.suf;

    return ret(val, pref, suf);
}

int main(){
//    freopen(TASK".in","r",stdin);   
//    freopen(TASK".out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);

    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d%d%d", &l[i], &r[i], &w[i]);
        l[i]--;
        r[i]--;
        A[i] = 1;
        B[i] = (int) 1e9;
    }

    for (int it = 0; it < 35; it++) {
        vector<pair<int, int > > ev;

        for (int i = 0; i < k; i++) {
	        if (A[i] == B[i]) continue;
            mid[i] = (A[i] + B[i] + 1) / 2;

            ev.pb(mp(-mid[i], i + 1)); 
        }

        for (int i = 0; i < n; i++) ev.pb(mp(-h[i], -i - 1));

        sort(ev.begin(), ev.end());
        init(1, 0, n - 1);

        for (int i = 0; i < ev.size(); i++) {
            if (ev[i].S < 0) {
                int x = -ev[i].S - 1;
                add(1, 0, n - 1, x);
            } else {
                int id = ev[i].S - 1;

                if (fin(1, 0, n - 1, l[id], r[id]).val >= w[id]) {
                    A[id] = mid[id];
                } else {
                    B[id] = mid[id] - 1;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) printf("%d\n", A[i]);
    return 0;
}