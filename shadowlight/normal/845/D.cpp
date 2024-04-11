#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n;
    cin >> n;
    int speed = INF;
    bool can = true;
    int cnt = 0;
    int allow = INF;
    vector <int> zn;
    int streak = 0;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> speed;
            while (zn.size() && speed > zn.back()) {
                cnt++;
                zn.pop_back();
            }
        } else if (type == 2) {
            if (!can) {
                cnt += streak;
                streak = 0;
            }
        } else if (type == 3) {
            cin >> allow;
            zn.push_back(allow);
            while (zn.size() && speed > zn.back()) {
                cnt++;
                zn.pop_back();
            }
        } else if (type == 4) {
            can = true;
            streak = 0;
        } else if (type == 5) {
            allow = INF;
            zn.clear();
        } else {
            streak++;
            can = false;
        }
    }
    cout << cnt;
}