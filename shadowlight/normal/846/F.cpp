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
    ll n;
    cin >> n;
    vector <vector <ll> > pos(MAXN);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    ll res = 0;
    for (int id = 0; id < MAXN; id++) {
        pos[id].push_back(n);
        for (int i = 0; i < (int) pos[id].size() - 1; i++) {
            res += 2LL * (pos[id][i] + 1) * (pos[id][i + 1] - pos[id][i]);
        }
    }
    cout.precision(20);
    cout << (double) (res - n) / (double) (n * n);

}