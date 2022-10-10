#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 1e5 + 10;
ii pts[MAXN], ans[MAXN];
int t[MAXN], fir[MAXN];
int n, w, h;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> h;

    map<int, vector<ii>> FUCK;
    for(int i = 0; i < n; i++) {
        int g, p;
        cin >> g >> p >> t[i];
        if(g == 1)
            pts[i] = {p, 0};
        else
            pts[i] = {0, p};
        FUCK[p - t[i]].push_back({pts[i][0] - (pts[i][1] >= 1 ? t[i] : 0), i});
    }

    for(auto &[x, v] : FUCK) {
        auto sv = v;
        sort(sv.begin(), sv.end());
        vector<ii> fin;
        for(auto &[x, idx] : v) {
            ii res = {(pts[idx][0] ?: w), (pts[idx][1] ?: h)};
            fin.push_back({res[0], -res[1]});
        }
        sort(fin.begin(), fin.end());
        for(int i = 0; i < fin.size(); i++) {
            //cout << pts[sv[i][1]][0] << " " << pts[sv[i][1]][1] << "   " << fin[i][0] << " " << -fin[i][1] << '\n';
            ans[sv[i][1]] = {fin[i][0], -fin[i][1]};
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i][0] << " " << ans[i][1] << '\n';
}