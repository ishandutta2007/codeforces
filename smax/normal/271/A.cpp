#include <bits/stdc++.h>
using namespace std;

bool f(int y) {
    int o = to_string(y).length();
    set<int> digits;
    while (y > 0) {
        digits.insert(y % 10);
        y /= 10;
    }
    return digits.size() == o;
}

int main() {
    int y;
    cin >> y;
    y++;
    while (!f(y))
        y++;
    
    cout << y << endl;
    
    return 0;
}