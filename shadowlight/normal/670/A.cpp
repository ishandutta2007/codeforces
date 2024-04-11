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
    int sum = 0;
    if (n <= 2) {
        cout << 0 << " " << n;
        return 0;
    } else {
        n -= 2;
        while (n >= 7) {
            sum += 2;
            n -= 7;
        }
        int a = sum + max(0, n - 5) + 2;
        n += 2;
        while (n >= 7) {
            sum += 2;
            n -= 7;
        }
        int b = sum + max(0, n - 5);
        cout << b << " " << a << "\n";
    }
}