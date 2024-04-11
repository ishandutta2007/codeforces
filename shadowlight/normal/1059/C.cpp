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
    int n, d = 1;
    cin >> n;
    int last = n;
    vector <int> res;
    while (last > 3) {
        for (int i = 0; i < (last + 1) / 2; i++) {
            res.push_back(d);
        }
        last /= 2;
        d *= 2;
    }
    if (last == 3) {
        res.push_back(d);
        res.push_back(d);
        res.push_back(3 * d);
    } else if (last == 2) {
        res.push_back(d);
        res.push_back(2 * d);
    } else {
        res.push_back(d);
    }
    for (int x : res) {
        cout << x << " ";
    }
}