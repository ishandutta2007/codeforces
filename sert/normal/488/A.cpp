#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

const int N = 1e6 + 34;

int st;

bool isgood(int x) {
    x = abs(x);
    while (x) {
        if (x % 10 == 8) return true;
        x /= 10;
    }
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> st;
    for (int i = 1; true; i++) {
        if (isgood(i + st)) {
            cout << i;
            return 0;
        }
    }
}