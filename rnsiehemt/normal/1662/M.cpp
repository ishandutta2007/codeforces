#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        int R = 0, W = 0;
        for (int i = 0; i < M; i++) {
            int r, w;
            cin >> r >> w;
            R = max(R, r);
            W = max(W, w);
        }
        if (R+W > N) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << string(R, 'R') << string(N-R, 'W') << "\n";
        }
    }
}