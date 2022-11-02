#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int R = 21, A = 360;
        vector<vector<bool>> c_edge(R, vector<bool>(A, true));
        vector<vector<bool>> a_edge(R, vector<bool>(A, true));
        for (int i = 0; i < N; i++) {
            char t;
            int a, b, c;
            cin >> t >> a >> b >> c;
            if (t == 'C') {
                while (b != c) {
                    c_edge[a][b] = false;
                    b = (b+1) % A;
                }
            } else {
                for (int r = a; r < b; r++) {
                    a_edge[r][c] = false;
                }
            }
        }
        vector<vector<bool>> seen(R, vector<bool>(A));
        function<bool(int, int)> go = [&](int r, int theta) -> bool {
            if (r == 0) {
                return true;
            }
            seen[r][theta] = true;
            if (c_edge[r][theta] && !seen[r-1][theta]) {
                if (go(r-1, theta)) {
                    return true;
                }
            }
            if (int ntheta = (theta + 1) % A; a_edge[r][ntheta] && !seen[r][ntheta]) {
                if (go(r, ntheta)) {
                    return true;
                }
            }
            if (int ntheta = (theta + A-1) % A; a_edge[r][theta] && !seen[r][ntheta]) {
                if (go(r, ntheta)) {
                    return true;
                }
            }
            if (r+1 < R && c_edge[r+1][theta] && !seen[r+1][theta]) {
                if (go(r+1, theta)) {
                    return true;
                }
            }
            return false;
        };
        cout << (go(R-1, 0) ? "YES" : "NO") << "\n";
    }
}