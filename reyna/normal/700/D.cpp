// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 1e5 + 5, sq = 2000, mo = 330, mod = 0;

int cur[N], o[N], res[N], a[N], curval, in[N], cnt[N], ql[N], qr[N], cc[N], used = N;
set<pair<int, int>> st, hf;
int cmp(int x, int y) {
    int gx = qr[x] / mo, gy = qr[y] / mo;
    if (gx == gy)
        return ql[x] < ql[y];
    return gx < gy;
}
void add(int pos, int x) {
    int val = a[pos];
    if (in[val]) st.erase(make_pair(cur[val], val)), in[val] = 0;
    cc[cur[val]]--;
    cur[val] += x;
    cc[cur[val]]++;
    if (cur[val] >= sq)
       st.insert(make_pair(cur[val], val)), in[val] = 1; 
}
void add_to(int x, int qu) {
    if (x >= sq) {
        for (int i = 0; i < qu; ++i)
            hf.insert(make_pair(x, N + used)), used++;
    } else {
        cnt[x] += qu;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    int xl = 0, xr = 0;
    for (int i = 0; i < q; ++i) {
        cin >> ql[i] >> qr[i];
        ql[i]--;
        o[i] = i;
    }
    sort(o, o + q, cmp);
    for (int _ = 0; _ < q; ++_) {
        int i = o[_];
        while (xl > ql[i]) add(--xl, +1);
        while (xr < qr[i]) add(xr++, +1);
        while (xl < ql[i]) add(xl++, -1);
        while (xr > qr[i]) add(--xr, -1);
        hf = st;
        used = N;
        for (int j = 1; j < sq; ++j)
            cnt[j] = cc[j];
        int last = -1;
        curval = 0;
        for (int j = 1; j < sq; ++j) if (cnt[j]) {
            if (last != -1) {
                curval += last + j;
                cnt[j]--;
                add_to(j + last, 1);
                last = -1;
            }
            if (cnt[j] & 1)
                last = j, cnt[j]--;
            curval += j * cnt[j];
            cnt[j] >>= 1;
            add_to(j + j, cnt[j]);
        }
        if (last != -1)
            hf.insert(make_pair(last, used)), used++;
        while ((int) hf.size() > 1) {
            auto it0 = hf.begin(), it1 = it0; ++it1;
            pair<int, int> nw = make_pair(it0->first + it1->first, used);
            used++;
            curval += it0->first + it1->first;
            hf.erase(it0);
            hf.erase(it1);
            hf.insert(nw);
        }
        res[i] = curval;
    }
    for (int i = 0; i < q; ++i)
        cout << res[i] << '\n';
}