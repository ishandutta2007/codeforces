#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long k = ((y2 - y1) / 2 + 1) * (x2 - x1 + 1) - (x2 - x1) / 2;
    cout << k << endl;
}