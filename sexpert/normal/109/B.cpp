#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt1e[3333], cnt2e[3333], cnt1i[3333], cnt2i[3333];
set<int> lk;

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

    lk.insert(1000000001);
    int amt = lk.size();
    //for(auto x : lk)
    //    cout << x << " ";
    //cout << '\n';

    int pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;

    int pre = 0, cur = 0;
    for(auto R : lk) {
        int L = pre;
        cnt1i[cur] += max(0, min(pr, R - 1) - max(pl, L) + 1);
        cnt1e[cur] += max(0, min(pr, R) - max(pl, L + 1) + 1);
        pre = R;
        cur++;
    }

    pre = 0, cur = 0;
    for(auto R : lk) {
        int L = pre;
        cnt2i[cur] += max(0, min(vr, R - 1) - max(vl, L) + 1);
        cnt2e[cur] += max(0, min(vr, R) - max(vl, L + 1) + 1);
        pre = R;
        cur++;
    }

    /*for(int i = 0; i <= amt; i++)
        if(cnt1i[i] + cnt1e[i] > 0)
            cout << i << " " << cnt1i[i] << " " << cnt1e[i] << '\n';

    cout << "===\n";

    for(int i = 0; i <= amt; i++)
        if(cnt2i[i] + cnt2e[i] > 0)
            cout << i << " " << cnt2i[i] << " " << cnt2e[i] << '\n';*/


    ll tot = 0;
    for(int i = 0; i <= amt; i++) {
        tot += cnt1e[i] * cnt2i[i + k];
        tot += cnt2e[i] * cnt1i[i + k];
    }

    if(k == 1) {
        for(auto x : lk)
            if(x >= vl && x <= vr && x >= pl && x <= pr)
                tot--;
    }

    cout << fixed << setprecision(12) << (double)tot/(double)((ll)(vr - vl + 1) * (ll)(pr - pl + 1)) << '\n';
}