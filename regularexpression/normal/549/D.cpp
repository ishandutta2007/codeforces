#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()

char a[111][111];
int b[111][111];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int x = a[i][j] == 'W' ? 1 : -1;
            if (b[i][j] != x) {
                ans++;
                x -= b[i][j];
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) b[k][l] += x;
                }
            }
        }
    }
    cout << ans;
    return 0;
}