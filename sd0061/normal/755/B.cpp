#include <bits/stdc++.h>
using namespace std;

int n , m;
int X , Y , Z;

int main() {
    set<string> H;
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++ i) {
        string str;
        cin >> str;
        H.insert(str);
    }
    for (int i = 0 ; i < m ; ++ i) {
        string str;
        cin >> str;
        if (H.count(str)) {
            -- X , -- Y , ++ Z;
        }
    }
    X += n , Y += m;
    while (1) {
        if (Z > 0) {
            -- Z;
        } else if (X > 0) {
            -- X;
        } else {
            puts("NO");
            return 0;
        }
        if (Z > 0) {
            -- Z;
        } else if (Y > 0) {
            -- Y;
        } else {
            puts("YES");
            return 0;
        }

    }
}