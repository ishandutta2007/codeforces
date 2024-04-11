#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int cnt[1005];
 
int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i = 0; i < n*n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if(n % 2 == 0) {
        int x = 0, y = 0;
        for(int i = 0; i < 1005; i++) {
            if(cnt[i] % 4 != 0) {
                cout << "NO\n";
                return 0;
            }
            while(cnt[i] > 0) {
                cnt[i] -= 4;
                ans[x][y] = ans[n - 1 - x][y] = ans[x][n - 1 - y] = ans[n - 1 - x][n - 1 - y] = i;
                y++;
                if(y >= n/2) {
                    x++;
                    y = 0;
                }
            }
        }
    }
    else {
        int mid = n/2;
        int xmid = 0, ymid = -1, x = 0, y = 0;
        for(int i = 0; i < 1005; i++) {
            if(cnt[i] % 2) {
                if(ans[mid][mid] != 0) {
                    cout << "NO\n";
                    return 0;
                }
                ans[mid][mid] = i;
                cnt[i]--;
            }
            if(cnt[i] % 4 == 2) {
                cnt[i] -= 2;
                if(ymid >= 0) {
                    if(ymid == mid) {
                        cout << "NO\n";
                        return 0;
                    }
                    ans[mid][ymid] = ans[mid][n - 1 - ymid] = i;
                    ymid++;
                }
                else {
                    ans[xmid][mid] = ans[n - 1 - xmid][mid] = i;
                    xmid++;
                    if(xmid == mid)
                        ymid = 0;
                }
            }
            while(cnt[i] > 0) {
                if(x == mid)
                    break;
                cnt[i] -= 4;
                ans[x][y] = ans[n - 1 - x][y] = ans[x][n - 1 - y] = ans[n - 1 - x][n - 1 - y] = i;
                y++;
                if(y == mid) {
                    x++;
                    y = 0;
                }
            }
        }
        for(int i = 0; i < 1005; i++) {
            while(cnt[i] > 0) {
                cnt[i] -= 2;
                if(ymid >= 0) {
                    ans[mid][ymid] = ans[mid][n - 1 - ymid] = i;
                    ymid++;
                }
                else {
                    ans[xmid][mid] = ans[n - 1 - xmid][mid] = i;
                    xmid++;
                    if(xmid == mid)
                        ymid = 0;
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}