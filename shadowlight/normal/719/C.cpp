#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    string s1 = "", s2 = "";
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '.') break;
        s1 += x;
    }
    cin >> s2;
    int fl = 0;
    int i = 0;
    while (k != 0 && i < s2.size() && i >= 0) {
        int x = s2[i] - '0';
        if (x >= 5) {
            k--;
            s2 = s2.substr(0, i);
            i--;
            if (i >= 0) {
                s2[i] = (char) (s2[i] + 1);
            } else {
                fl = 1;
                break;
            }
        } else {
            i++;
        }
    }
    if (fl) {
        int i = s1.size() - 1;
        while (i >= 0 && s1[i] - '0' == 9) {
            s1[i] = '0';
            i--;
        }
        if (i < 0) {
            s1 = '1' + s1;
        } else {
            s1[i] = (char) (s1[i] + 1);
        }
    }
    cout << s1;
    if (s2.size() != 0) {
        cout << "." << s2 << endl;
    }
}
/*
9 10
99999.445
*/