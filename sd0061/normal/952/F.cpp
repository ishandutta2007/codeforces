#include <bits/stdc++.h>
using namespace std;
const int N = 55;


int main() {
    string s;
    cin >> s;
    int res = 0 , x = 0 , f = 1;

    for (int i = 0 ; i < s.size() ; ) {
        char c = s[i];
        if (isdigit(c)) {
            while (isdigit(c)) {
                x = x * 10 + c - '0';
                ++ i;
                c = s[i];
            }
            res += f * x;
            if (c == '+') f = 1; else f = -1;
            x = c - '0';
            ++ i;
        } else {
            assert(0);
        }
    }
    cout << res << endl;
}