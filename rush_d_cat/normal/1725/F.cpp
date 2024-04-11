#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    
    for (int i = 0; i < n; i ++)
        cin >> l[i] >> r[i];


    auto max_cover = [&](vector<pair<int,int> > seg) {
        vector<pair<int, int> > upd;
        for (const auto &[x, y]: seg) {
            upd.push_back({x, 1});
            upd.push_back({y + 1, -1});
        }
        sort(upd.begin(), upd.end());
        int ans = 0;
        for (int i = 0, j = 0, pref = 0; i < upd.size(); i = j) {
            while (j < upd.size() and upd[j].first == upd[i].first) {
                pref += upd[j].second;
                j ++;       
            }
            //printf("[%d, %d)\n", i, j);
            ans = max(ans, pref);
        }
        return ans;
    };

    auto solve = [&](int k) {
        int m = 1<<k;
        vector<pair<int,int> > segs;
        for (int i = 0; i < n; i ++) {
            if (l[i] / m == r[i] / m) {
                segs.push_back({l[i] % m, r[i] % m});
            } else
            if (l[i] / m + 1 < r[i] / m) {
                segs.push_back({0, m - 1});
            } else {
                if (l[i] % m > r[i] % m) {
                    segs.push_back({l[i] % m, m - 1});
                    segs.push_back({0, r[i] % m});
                } else {
                    segs.push_back({0, m - 1});
                }
            }
        }
        //cout << "solve " << k << "\n"; 
        return max_cover(segs); 
    };

    vector<int> res(31);
    for (int i = 0; i < 31; i ++)
        res[i] = solve(i);

    int q;
    cin >> q;
    while (q --) {
        int w;
        cin >> w;       
        for (int i = 0; i < 31; i ++) {
            if (w >> i & 1) {
                cout << res[i] << "\n";
                break;
            }
        }
    }
}