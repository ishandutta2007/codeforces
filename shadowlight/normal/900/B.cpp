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
    int a, b, c;
    cin >> a >> b >> c;
    vector <int> exist(MAXN, 0);
    int now = 0;
    while (!exist[a]) {
        exist[a] = 1;
        a *= 10;
        if (a / b == c) {
            cout << now + 1;
            return 0;
        }
        now++;
        a %= b;
    }
    cout << -1;
}