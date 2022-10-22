#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    string s1 = "";
    int n = s.size();
    bool fl = 0;
    bool fl2 = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int num = s[i] - 'a';
        if (num != 0) {
            s1 += (char) (num - 1 + 'a');
            fl = 1;
            fl2 = 0;
        } else if (fl) {
            s1 += s.substr(i, n - i + 1);
            break;
        } else {
            s1 += 'a';
        }
    }
    if (fl2) {
        s1[n - 1] = 'z';
    }
    cout << s1;
}