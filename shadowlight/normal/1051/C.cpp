#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 107;

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
    vector <int> res(n, 0);
    vector <vector <int> > nums(MAXN);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[x].push_back(i);
    }
    map <int, bool> can;
    can[0] = true;
    vector <map <int, int> > pred(MAXN);
    for (int i = 0; i < MAXN; i++) {
        int cnt = nums[i].size();
        map <int, bool> ncan;
        if (!cnt || cnt == 2) {
            continue;
        }
        for (auto p : can) {
            ncan[p.first + 1] = true;
            pred[i][p.first + 1] = 1;
            ncan[p.first - 1] = true;
            pred[i][p.first - 1] = cnt - 1;
            if (cnt > 1) {
                ncan[p.first] = true;
                pred[i][p.first] = 0;
            }
        }
        can = ncan;
    }
    if (!can[0]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int bal = 0;
    for (int i = MAXN - 1; i >= 0; i--) {
        int cnt = nums[i].size();
        int x = pred[i][bal];
        for (int j = 0; j < x; j++) {
            res[nums[i][j]] = 0;
        }
        for (int j = x; j < nums[i].size(); j++) {
            res[nums[i][j]] = 1;
        }
        if (x == 1) {
            bal--;
        }
        if (x == cnt - 1) {
            bal++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (char) (res[i] + 'A');
    }
}