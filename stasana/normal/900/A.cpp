#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > 0) {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }
    if (cnt1 == 1 || cnt2 == 1 || cnt1 == 0 || cnt2 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}