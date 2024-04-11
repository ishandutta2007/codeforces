#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n;
    cin >> n;
    int minx = -INF, maxx = INF;
    set <int> q, mq, lq;
    int st = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int p;
        cin >> p;
        if (s == "ADD") {
            if (p > maxx) {
                mq.insert(p);
            } else if (p < minx) {
                lq.insert(p);
            } else {
                q.insert(p);
            }
        } else {
            if (p > maxx || p < minx) {
                cout << "0\n";
                return 0;
            }
            if (p == maxx) {
                mq.erase(p);
            } else if (p == minx) {
                lq.erase(p);
            } else if (q.find(p) == q.end()) {
                cout << "0\n";
                return 0;
            } else {
                st = st * 2 % INF;
            }
            for (int x : q) {
                if (x < p) {
                    lq.insert(x);
                } else if (x > p) {
                    mq.insert(x);
                }
            }
            minx = (lq.size() ? *lq.rbegin() : -INF);
            maxx = (mq.size() ? *mq.begin() : INF);
            q.clear();
        }
    }
    cout << (ll) st * (ll) (q.size() + 1) % INF;
}