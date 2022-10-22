#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m, g;
    cin >> n >> m;
    if (n - m - 1 >= m - 1) {
        cout << m + 1;
    } else if (m - 1 != 0) {
        cout << m - 1;
    } else {
        cout << 1;
    }
}