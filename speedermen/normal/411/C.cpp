#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    vector <int> a(4), b(4);
    for (int i = 0; i < 4; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int it = 0; it < 2; ++it) {
        bool isOk = false;
        for (int jt = 0; jt < 2; ++jt) {
            if (it == 0) {
                isOk |= a[jt] > max(b[2], b[3]) && b[jt ^ 1] > max(a[2], a[3]);
            } else {
                isOk |= ((a[jt] > b[2] && b[jt ^ 1] > a[3]) || (a[jt ^ 1] > b[2] && b[jt] > a[3])) &&
                        ((a[jt] > b[3] && b[jt ^ 1] > a[2]) || (a[jt ^ 1] > b[3] && b[jt] > a[2]));
            }
        }
        if (isOk) {
            cout << "Team " << it + isOk << '\n';
            exit(0);
        }
        for (int jt = 0; jt < 2; ++jt) {
            swap(a[jt], a[jt + 2]);
            swap(b[jt], b[jt + 2]);
        }
    }
    cout << "Draw\n";
    return 0;
}