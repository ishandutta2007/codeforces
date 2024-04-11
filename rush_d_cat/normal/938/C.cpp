#include <iostream>
#include <vector>
using namespace std;
int t, x;
vector<int> v;
int main() {
    cin >> t;
    while (t --) {
        cin >> x; v.clear();
        if (x == 0) {
            printf("1 1\n");
            continue;
        }

        for (int i = 1; i * i <= x; i ++) {
            if (x % i == 0) {
                v.push_back(i);
            }
        }

        bool fg = 0;
        for (int i = 0; i < v.size(); i ++) {
            int a = v[i], b = x / v[i];
            if ((a + b) % 2) continue;
            if (a == b) continue;
            int n = (b + a) / 2;
            int k = (b - a) / 2; // n / m = k
            if (n / (n/k) == k) {
                printf("%d %d\n", n, n/k);
                fg = 1;
                break;
            }
        }

        if (fg == 0) {
            printf("-1\n");
        }
    }
}