#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstdio>
#include <cmath>

using namespace std;

int x, y;
int cnt = 0;

void generate(int a1, int a2, int a3) {
    if (a1 == x && a2 == x && a3 == x) {
        return;
    }
    int new_a = min(a3 + a2 - 1, x);
    cnt++;
    generate(a2, a3, new_a);
}
int main() {
    cin >> x >> y;
    generate(y, y, y);
    cout << cnt;
}