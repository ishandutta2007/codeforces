#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int main() {
    int x;
    string a , b;
    cin >> x >> a >> b;
    if (b == "week") {
        int y = 52;
        if (x == 5 || x == 6)
            ++ y;
        cout << y << endl;
    } else {
        if (x <= 29) {
            cout << 12 << endl;
        } else if (x <= 30) {
            cout << 11 << endl;
        } else {
            cout << 7 << endl;
        }
    }
    return 0;
}