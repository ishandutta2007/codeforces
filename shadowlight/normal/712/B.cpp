#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    int bal1 = 0, bal2 = 0;
    if (s.size() % 2 == 1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (x == 'R') {
            bal1++;
        } else if (x == 'L') {
            bal1--;
        } else if (x == 'U') {
            bal2++;
        } else {
            bal2--;
        }
    }
    cout << (abs(bal1) + abs(bal2)) / 2;
}