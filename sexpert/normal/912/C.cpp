#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m;
ll base, dam, inc, ans;
const int MAXN = 1e5 + 10;
int sta[MAXN], lh[MAXN];
ll maxh[MAXN], reg[MAXN];
vector<ii> upd[MAXN];
vector<array<int, 3>> eve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> base >> inc >> dam;
    for(int i = 0; i < n; i++) {
        int M, S, R;
        cin >> M >> S >> R;
        upd[i].push_back({0, S});
        maxh[i] = M;
        reg[i] = R;
    }
    for(int i = 0; i < m; i++) {
        int ti, en, he;
        cin >> ti >> en >> he;
        en--;
        upd[en].push_back({ti, he});
    }
    for(int i = 0; i < n; i++) {
        sort(upd[i].begin(), upd[i].end());
        for(int u = 0; u < upd[i].size(); u++) {
            auto q = upd[i][u];
            eve.push_back({q.first, i, (q.second <= dam)});
            if(reg[i] > 0 && q.second <= dam) {
                int dif = dam + 1 - q.second;
                int ti = (dif + reg[i] - 1)/reg[i];
                if(u + 1 == upd[i].size() || q.first + ti < upd[i][u + 1].first)
                    eve.push_back({q.first + ti, i, 0});
            }
            lh[i] = q.second;
        }
    }
    sort(eve.begin(), eve.end());
    ll cnt = 0, prv = -1;
    for(auto e : eve) {
        if(prv != e[0]) {
            prv = e[0];
            ans = max(ans, (base + inc * (prv - 1)) * cnt);
        }
        cnt -= sta[e[1]];
        sta[e[1]] = e[2];
        cnt += sta[e[1]];
    }
    ans = max(ans, (base + inc * ((eve.back())[0])) * cnt);
    if(inc > 0)
        for(int i = 0; i < n; i++)
            if(maxh[i] <= dam || reg[i] == 0 && lh[i] <= dam)
                ans = -1;
    cout << ans << '\n';
}