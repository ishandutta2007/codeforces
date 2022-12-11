#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    --n;
    int state = 1, res = 0;
    while (n > 0) {
        if (state == 1) {
            if (a < b) {
                state = 2;
                res += a;
            } else {
                state = 3;
                res += b;
            }
        } else if (state == 2) {
            if (a < c) {
                state = 1;
                res += a;
            } else {
                state = 3;
                res += c;
            }
        } else {
            if (c < b) {
                state = 2;
                res += c;
            } else {
                state = 1;
                res += b;
            }
        }
        --n;
    }
    cout << res;
    return 0;
}