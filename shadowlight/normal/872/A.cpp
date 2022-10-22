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
    int a = 10, b = 10;
    int n, m;
    cin >> n >> m;
    vector <int> inA(10, 0), inB(10);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inA[x] = 1;
        a = min(a, x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        inB[x] = 1;
        b = min(b, x);
    }
    for (int i = 0; i < 10; i++) {
        if (inA[i] && inB[i]) {
            cout << i;
            return 0;
        }
    }
    if (a > b) {
        swap(a, b);
    }
    cout << 10 * a + b;
}