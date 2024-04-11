#include <bits/stdc++.h>

using namespace std;

int ans1[4][2] = {{1, 1}, {1, 2}, {1, 3}, {1, 4}};
int ans2[4][2] = {{3, 1}, {3, 3}, {4, 1}, {4, 3}};

int main() {
    string s; cin >> s;
    
    int t1 = 0, t2 = 0;
    
    for (char c: s) {
        if (c == '0') {
            printf("%d %d\n", ans1[t1][0], ans1[t1][1]);
            t1 = (t1 + 1) % 4;
        } else {
            printf("%d %d\n", ans2[t2][0], ans2[t2][1]);
            t2 = (t2 + 1) % 4;
        }
    }
    
    return 0;
}