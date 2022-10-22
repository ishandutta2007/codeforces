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
    map <int, int> cnt;
    int a = -1, b = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        if (a == -1) {
            a = x;
        } else if (b == -1 && a != x) {
            b = x;
        }
    }
    if (cnt.size() != 2 || cnt[a] != n / 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << a << " " << b << "\n";
    }
}