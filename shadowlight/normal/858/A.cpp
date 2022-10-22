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
    ll n, k;
    cin >> n >> k;
    ll a = 0, b = 0;
    ll m = n;
    while (n % 2 == 0) {
        a++;
        n /= 2;
    }
    while (n % 5 == 0) {
        b++;
        n /= 5;
    }
    for (int i = 0; i < k - a; i++) {
        m *= 2LL;
    }
    for (int i = 0; i < k - b; i++) {
        m *= 5LL;
    }
    cout << m;
}