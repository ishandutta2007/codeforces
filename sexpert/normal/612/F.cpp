#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int INF = 1e9;
int dp[MAXN][MAXN], n, s;
// start at a[0], go (right / left) to a[2]
array<int, 3> back[MAXN][MAXN];
vector<int> all[MAXN], v, sv;

void upd(int stage, int pos, int val, int st, int dir, int en) {
    if(dp[stage][pos] > val) {
        dp[stage][pos] = val;
        back[stage][pos] = {st, dir, en};
    }
}

void trace(int sta, int pos, vector<int> &res, int dir = 0, int go = 0) {
    if(sta > 0)
        trace(sta - 1, back[sta][pos][0], res, back[sta][pos][1], back[sta][pos][2]);
    if(sta < sv.size()) {
        if(dir == 1) {
            vector<int> tor;
            tor.push_back(0);
            for(int i = 0; i < n; i++) {
                if(v[(pos + i) % n] == sta + 1)
                    tor.push_back(i);
            }
            for(int i = 1; i <= go + 1; i++)
                res.push_back(tor[i] - tor[i - 1]);
            for(int i = tor.size() - 1; i > go + 1; i--)
                res.push_back(((i == tor.size() - 1) ? -(tor[go + 1] + n - tor[i]) : tor[i] - tor[i + 1]));
        }
        else {
            vector<int> tol;
            tol.push_back(0);
            for(int i = 0; i < n; i++) {
                if(v[(pos + n - i) % n] == sta + 1)
                    tol.push_back(i);
            }
            for(int i = 0; i <= go; i++)
                res.push_back(tol[i] - tol[i + 1]);
            for(int i = tol.size() - 1; i > go + 1; i--)
                res.push_back((i == tol.size() - 1 ? tol[go + 1] + n - tol[i] : tol[i + 1] - tol[i]));
        }
    }
}

int main() {
    cin >> n >> s;
    s--;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    sv = v;
    map<int, int> to;
    sort(sv.begin(), sv.end());
    sv.erase(unique(sv.begin(), sv.end()), sv.end());
    for(int i = 0; i < sv.size(); i++)
        to[sv[i]] = i + 1;
    for(int i = 0; i < n; i++) {
        v[i] = to[v[i]];
        all[v[i]].push_back(i);
    }
    all[0].push_back(s);
    for(int i = 0; i < MAXN; i++)
        fill(dp[i], dp[i] + MAXN, INF);

    dp[0][s] = 0;
    for(int x = 0; x + 1 <= sv.size(); x++) {
        for(auto st : all[x]) {
            vector<int> tor, tol;
            for(int i = 0; i < n; i++) {
                if(v[(st + i) % n] == x + 1)
                    tor.push_back(i);
            }
            for(int i = 0; i < n; i++) {
                if(v[(st + n - i) % n] == x + 1)
                    tol.push_back(i);
            }
            for(int d = 0; d < tor.size(); d++) {
                if(d == tor.size() - 1)
                    upd(x + 1, (st + tor[d]) % n, dp[x][st] + tor[d], st, 1, d);
                else
                    upd(x + 1, (st + tor[d + 1]) % n, dp[x][st] + 2*tor[d] + (n - tor[d + 1]), st, 1, d);
            }
            for(int d = 0; d < tol.size(); d++) {
                if(d == tor.size() - 1)
                    upd(x + 1, (st + n - tol[d]) % n, dp[x][st] + tol[d], st, -1, d);
                else
                    upd(x + 1, (st + n - tol[d + 1]) % n, dp[x][st] + 2*tol[d] + (n - tol[d + 1]), st, -1, d);
            }
        }
    }
    int ans = INF, st;
    for(auto x : all[sv.size()]) {
        if(dp[sv.size()][x] < ans) {
            ans = min(ans, dp[sv.size()][x]);
            st = x;
        }
    }
    cout << ans << '\n';
    vector<int> res;
    trace(sv.size(), st, res);
    for(auto x : res)
        cout << (x >= 0 ? '+' : '-') << abs(x) << '\n';
}