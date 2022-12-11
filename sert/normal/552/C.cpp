#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
const long long N = 1e5 + 34;
typedef long long ll;
ll cur, n, m;
void go(ll st) {
    if (cur == m || cur == -m) {
        cout << "YES\n";
        exit(0);
    }
    if (st / 10 > m)
        return;
    if ((m - cur + st * N) % st)
        return;
    cur -= st;
    go(st * n);
    cur += st;
    go(st * n);
    cur += st;
    go(st * n);
    cur -= st;
}
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> m;
    if (n < 4) {
        cout << "YES\n";
        return 0;
    }
    go(1);
    cout << "NO\n";
    //cout << clock();
}