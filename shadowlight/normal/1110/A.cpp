#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    int b, k;
    cin >> b >> k;
    int x;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        cin >> x;
        sum += x;
    }
    if (b % 2) {
        cout << (sum % 2 ? "odd" : "even");
    } else {
        cout << (x % 2 ? "odd" : "even");
    }
}