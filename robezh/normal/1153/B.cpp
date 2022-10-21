#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;

int n, m, h;
int a[N], b[N];
int mat[N][N];
int res[N][N];

int main() {
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j]) {
                res[i][j] = min(a[i], b[j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << res[i][j] << " ";
        cout << endl;
    }

}