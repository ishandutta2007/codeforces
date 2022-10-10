#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n <= 2) {
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> ans(n, vector<int>(n));
    ans[2][0] = n*n - 8;
    ans[2][1] = n*n - 1;
    ans[2][2] = n*n - 2;
    ans[1][0] = n*n - 5;
    ans[1][1] = n*n - 6;
    ans[1][2] = n*n - 3;
    ans[0][0] = n*n - 7;
    ans[0][1] = n*n - 4;
    ans[0][2] = n*n;
    int cur = 1;
    for(int lay = n - 3; lay > 0; lay--) {
        if(lay % 2) {
            for(int j = 0; j < lay + 3; j++)
                ans[j][lay + 2] = cur++;
            for(int i = lay + 1; i >= 0; i--)
                ans[lay + 2][i] = cur++;
        }
        else {
            for(int i = 0; i < lay + 3; i++)
                ans[lay + 2][i] = cur++;
            for(int j = lay + 1; j >= 0; j--)
                ans[j][lay + 2] = cur++;
        }
    }
    for(int i = 0; i <n ; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}