#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int INF = 1e9;
int m, k, n, s, bads, req[MAXN], ireq[MAXN], ans[MAXN], seq[MAXN];
bool fix[MAXN];

void finish(int l, int r) {
    vector<int> ans;
    if(r < l + k)
        r = l + k;
    int fl = l, st = 0;
    while(fl % k) {
        st++;
        ans.push_back(st);
        fl--;
    }
    while(fl / k >= n) {
        for(int i = 0; i < k; i++) {
            st++;
            ans.push_back(st);
            fl--;
        }
    }
    int fc = r - l;
    for(int i = l; i < r; i++) {
        int x = seq[i];
        if(ireq[x] != INF) {
            if(ireq[x] > 0) {
                ireq[x]--;
                fix[i] = true;
            }
        }
    }
    for(int i = l; i < r; i++) {
        if(fc == k)
            break;
        if(fix[i])
            continue;
        ans.push_back(i + 1);
        fc--;
    }
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> k >> n >> s;
    for(int i = 0; i < MAXN; i++)
        ireq[i] = req[i] = INF;
    for(int i = 0; i < m; i++)
        cin >> seq[i];
    for(int i = 0; i < s; i++) {
        int x;
        cin >> x;
        if(req[x] == INF) {
            bads++;
            req[x] = 0;
        }
        req[x]++;
        ireq[x] = req[x];
    }
    int lp = 0, rp = 0;
    while(lp < m) {
        if(rp < m && bads > 0) {
            int x = seq[rp];
            rp++;
            if(req[x] != INF) {
                req[x]--;
                if(req[x] == 0)
                    bads--;
            }
        }
        else {
            if(bads == 0) {
                int tot = lp/k + 1 + (m - max(rp, lp + k))/k;
                if(tot >= n) {
                    finish(lp, rp);
                    return 0;
                }
            }
            int x = seq[lp];
            lp++;
            if(req[x] != INF) {
                if(req[x] == 0)
                    bads++;
                req[x]++;
            }
        }
    }
    cout << -1 << endl;
}