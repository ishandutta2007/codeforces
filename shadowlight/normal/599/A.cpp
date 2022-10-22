#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout <<min(min(a + b + c, 2 * a + 2 * b), min(2 * a + 2 * c, 2 * b + 2 * c));
}