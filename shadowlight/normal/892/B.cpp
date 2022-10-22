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
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> alive;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        while (alive.size() && alive.back() >= i - l) {
            alive.pop_back();
        }
        alive.push_back(i);
    }
    cout << alive.size();
}