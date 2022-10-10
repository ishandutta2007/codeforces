#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

set<int> lk;
set<int> goodpos, badpos;

const int MAXN = 1e5 + 10;
ii a[MAXN];
int tpos[MAXN], pos[MAXN], target[MAXN], cur[MAXN], good[MAXN];
vector<ii> ops;

void flip(int p1, int p2) {
    if(p1 == p2)
        return;
    int x = cur[p1], y = cur[p2];
    pos[x] = p2;
    pos[y] = p1;
    cur[p1] = y;
    cur[p2] = x;
    ops.push_back({p1, p2});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int len = 1; len <= 9; len++) {
        for(int x = 0; x < (1 << len); x++) {
            int res = 0;
            for(int i = 0; i < len; i++) {
                if(x & (1 << i))
                    res = res * 10 + 4;
                else
                    res = res * 10 + 7;
            }
            lk.insert(res);
        }
    }

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = {i, x};
        pos[i] = i;
        if(lk.count(x)) {
            goodpos.insert(i);
            good[i] = 1;
        }
        else
            badpos.insert(i);
    }

    iota(target + 1, target + n + 1, 1);
    sort(target + 1, target + n + 1, [&](int x, int y){ return make_pair(a[x][1], x) < make_pair(a[y][1], y); });

    //for(int i = 1; i <= n; i++)
    //    cout << target[i] << " ";
    //cout << '\n';

    for(int i = 1; i <= n; i++)
        tpos[target[i]] = i;

    if(goodpos.empty()) {
        for(int i = 1; i <= n; i++) {
            if(tpos[i] != i) {
                cout << "-1\n";
                return 0;
            }
        }
        cout << "0\n";
        return 0;
    }

    iota(cur + 1, cur + n + 1, 1);
    iota(pos + 1, pos + n + 1, 1);

    /*for(int i = 1; i <= n; i++)
        cout << tpos[i] << " ";
    cout << '\n';

    for(int i = 1; i <= n; i++)
        cout << good[i] << " ";
    cout << '\n';*/

    int joker = -1;
    for(int i = 1; i <= n; i++)
        if(good[i])
            joker = i;

    vector<int> monogon_orz;
    for(int i = 1; i <= n; i++) {
        if(i == joker)
            continue;
        if(tpos[i] != pos[i]) {
            flip(pos[joker], tpos[i]);
            flip(pos[i], tpos[i]);
        }
    }

    cout << ops.size() << '\n';
    for(auto p : ops)
        cout << p[0] << " " << p[1] << '\n';
}