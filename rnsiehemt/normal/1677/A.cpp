#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<vector<int>> lless(N, vector<int>(N));
        vector<vector<int>> rless(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            int ll = 0;
            for (int j = 0; j < N; j++) {
                if (p[j] < p[i]) {
                    ll++;
                }
                lless[i][j] = ll;
            }
            int rl = 0;
            for (int j = N-1; j >= 0; j--) {
                if (p[j] < p[i]) {
                    rl++;
                }
                rless[i][j] = rl;
            }
        }
        long long ans = 0;
        for (int j = 0; j+1 < N; j++) {
            for (int i = 1; i < j; i++) {
                ans += (long long) lless[j][i-1] * rless[i][j+1];
            }
        }
        cout << ans << "\n";
    }
}