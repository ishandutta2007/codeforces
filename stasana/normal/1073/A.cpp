//    -
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            cout << "YES";
            cout << endl << s[i - 1] << s[i];
            return 0;
        }
    }
    cout << "NO";
    return 0;
}