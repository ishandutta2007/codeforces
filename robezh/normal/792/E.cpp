#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18;
const int N = 505;
typedef pair<int, ll> P;

struct VC {
    P ps[2 * 32000];
    int sz = 0;
    void push_back(P p) {
        ps[sz] = p;
        sz++;
    }
    void clear() {
        sz = 0;
    }

    void copy(VC &o) {
        sz = o.sz;
        for(int i = 0; i < sz; i++) ps[i] = o.ps[i];
    }

    P & operator [] (int id) {
        return ps[id];
    }

} cur, n_cur, nxt;

int n, a[N], tmp[N];

void get_list(int x, VC &res) {
    res.clear();
    for (int i = 1, j = 0; i <= x; i = j + 1)  {
        int sz = x / i;
        int k = i;
        j = x / (x / i);
        if(res.sz == 0 || res[res.sz-1].first > sz) res.push_back({sz, k});
        else res[res.sz-1].second = min(res[res.sz-1].second, (ll)k);
        if(x % sz == 0) res.push_back({sz - 1, x / sz});
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    get_list(a[0], cur);
    int r = 1;
    for(int i = 1; i < n; i++) {
//        while(r < n && a[i] == a[r]) r++;
        get_list(a[i], n_cur);

        nxt.clear();
        int pt = 0;
        int las = -1;
        for(int j = 0; j < n_cur.sz; j++) {
            P p = n_cur[j];
            if(p.first == las) continue;
            las = p.first;
            while(pt < cur.sz && cur[pt].first > p.first) pt++;
            if(pt < cur.sz && cur[pt].first == p.first)
                nxt.push_back({p.first, cur[pt].second + p.second});
        }
        cur.copy(nxt);
    }
    cout << cur[0].second << endl;


}