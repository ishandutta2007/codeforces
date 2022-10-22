#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;

const long long INF = 1e9 + 7;
int main() {
    int n, h, m;
    scanf("%d", &n);
    scanf("%d:%d", &h, &m);
    if (h > n || h == 24) {
        if (h % 10 == 0) {
            h = 10;
        } else {
            h = h % 10;
        }
    } else if (h == 0 && n == 12) {
        h = 1;
    }
    if (m > 59) {
        m = m % 10;
    }
    cout << h / 10 << h % 10 << ":" << m / 10 << m % 10 << endl;
}