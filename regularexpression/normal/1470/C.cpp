#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ii;
    while (true) {
        int i = rnd() % n;
        if (ask(i) > k) {
            ii = i;
            break;
        }
    }
    while (ask(ii) > k) {
        --ii;
        if (ii < 0)
            ii += n;
    }
    cout << "! " << ii + 1 << endl;
    return 0;
}