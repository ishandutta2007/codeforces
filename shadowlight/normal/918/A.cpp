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
    set <int> f;
    int a = 1, b = 1;
    f.insert(1);
    while (b < MAXN) {
        f.insert(b);
        int c = a + b;
        a = b;
        b = c;
    }
    for (int i = 1; i <= n; i++) {
        if (f.find(i) == f.end()) {
            cout << "o";
        } else {
            cout << "O";
        }
    }
}