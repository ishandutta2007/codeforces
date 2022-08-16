#include <iostream>

using namespace std;

const int MX = 1010;
int a[MX];

int main() {
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    int nxt = 1;
    while (nxt <= n) {
        int hi = -1;
        for (int k = min(n, nxt + r - 1); k > max(0, nxt - r); k--)
            if (a[k]) {
                hi = k;
                break;
            }
        if (hi == -1) {
            res = -1;
            break;
        }
        nxt = hi + r;
        res++;
    }
    cout << res << endl;
    return 0;
}