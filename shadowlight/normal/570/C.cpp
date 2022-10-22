#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n, m, pos, k = 0;
    char x;
    string str;
    cin >> n >> m;
    cin >> str;
    for (int j = 1; j < n; j++) {
        if (str[j] == '.' && str[j - 1] == '.') {
            k++;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> pos >> x;
        if (x == '.') {
            if (pos > 1 && str[pos - 2] == '.' && str[pos - 1] != '.') k++;
            if (pos < n && str[pos] == '.' && str[pos - 1] != '.') k++;
        } else {
            if (pos > 1 && str[pos - 2] == '.' && str[pos - 1] == '.') k--;
            if (pos < n && str[pos] == '.' && str[pos - 1] == '.') k--;
        }
        str[pos - 1] = x;
        cout << k << endl;
    }
}