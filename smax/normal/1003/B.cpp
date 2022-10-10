
// Problem : B. Binary String Constructing
// Contest : Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int a, b, x;
    cin >> a >> b >> x;
    
    int n = a + b, num = 0;
    for (int i=0; i<n; i++) {
        if (i == 0) {
            if (a > b) {
                num = 0;
                a--;
            } else {
                num = 1;
                b--;
            }
        } else if (x > 1) {
            if (num == 0) {
                num = 1;
                b--;
            } else {
                num = 0;
                a--;
            }
            if (i > 0)
                x--;
        } else {
            if (num == 0) {
                if (a > 0) {
                    num = 0;
                    a--;
                } else {
                    num = 1;
                    b--;
                }
            } else {
                if (b > 0) {
                    num = 1;
                    b--;
                } else {
                    num = 0;
                    a--;
                }
            }
        }
        cout << num;
    }
    cout << "\n";

    return 0;
}