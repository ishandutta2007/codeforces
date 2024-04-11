#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

bool check(int x) {
    int a = sqrt(x);
    return a * a == x;
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
    int x;
    cin >> x;
    vector <int> a;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    int N = a.size();
    reverse(a.begin(), a.end());
    int mink = INF;
    for (int mask = 0; mask < (1 << N); mask++) {
        bool start = true, can = true;
        int now = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) continue;
            if (!a[i] && start) {
                can = false;
                break;
            }
            start = false;
            now = 10 * now + a[i];
        }
        if (can && check(now)) {
            mink = min(mink, __builtin_popcount(mask));
        }
    }
    cout << (mink == N ? -1 : mink);
}