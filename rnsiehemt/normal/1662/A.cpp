#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> b(11);
        for (int i = 0; i < N; i++) {
            int bi, di;
            cin >> bi >> di;
            b[di] = max(b[di], bi);
        }
        int s = 0;
        for (int j = 1; j <= 10; j++) {
            if (!b[j]) {
                s = -1;
                break;
            }
            s += b[j];
        }
        if (s == -1) {
            cout << "MOREPROBLEMS\n";
        } else {
            cout << s << "\n";
        }
    }
}