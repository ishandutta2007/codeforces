#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;
typedef pair<int, int> P;

int n, m;
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a]++;
    }

    vector<vector<int> > dp(3, vector<int>(3, 0));
    for(int i = 1; i <= m; i++) {
        vector<vector<int> > new_dp(3, vector<int>(3, 0));
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                for(int z = 0; z < 3; z++) {
                    if(x + y + z > cnt[i]) continue;
                    new_dp[y][z] = max(new_dp[y][z], dp[x][y] + z + (cnt[i] - x - y - z) / 3);
                }
            }
        }
        swap(dp, new_dp);
    }
    cout << dp[0][0] << endl;


}