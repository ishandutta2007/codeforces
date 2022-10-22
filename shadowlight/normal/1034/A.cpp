#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 15e6 + 7;
const double EPS = 1e-8;

vector <int> d;
vector <int> pr;

vector <int> cnt;

void init() {
    d.resize(MAXN, -1);
    for (int i = 2; i < MAXN; i++) {
        if (d[i] == -1) {
            d[i] = pr.size();
            pr.push_back(i);
        }
        for (int j = 0; j <= d[i] && pr[j] * i < MAXN; j++) {
            d[pr[j] * i] = j;
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    init();
    int n;
    cin >> n;
    vector <int> del(MAXN, 0);
    vector <int> was(MAXN, INF), cntd(MAXN, 0);
    int res = INF;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int pred = -1;
        int now = 0;
        while (x != 1) {
            if (pr[d[x]] != pred) {
                if (pred != -1) {
                    if (was[pred] > now) {
                        was[pred] = now;
                        cntd[pred] = 1;
                    } else if (was[pred] == now) {
                        cntd[pred]++;
                    }
                }
                del[pr[d[x]]]++;
                now = 1;
            }
            now++;
            pred = pr[d[x]];
            x /= pred;
        }
        if (pred != -1) {
            if (was[pred] > now) {
                was[pred] = now;
                cntd[pred] = 1;
            } else if (was[pred] == now) {
                cntd[pred]++;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (del[i] && del[i] != n) {
            res = min(res, n - del[i]);
            continue;
        }
        if (cntd[i] == n || !cntd[i]) continue;
        //cout << i << " " << del[i] << " " << cntd[i] << "\n";
        res = min(res, cntd[i]);
    }
    cout << (res == INF ? -1 : res);
}