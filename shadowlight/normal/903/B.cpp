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
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector <bool> turns;
    while (h2 > 0) {
        if (h1 > a2 || h2 <= a1) {
            turns.push_back(0);
            h2 -= a1;
        } else {
            turns.push_back(1);
            h1 += c1;
        }
        h1 -= a2;
    }
    cout << turns.size() << "\n";
    for (auto x : turns) {
        if (x) {
            cout << "HEAL\n";
        } else {
            cout << "STRIKE\n";
        }
    }
}