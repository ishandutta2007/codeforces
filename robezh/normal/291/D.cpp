#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e4 + 50, K = 22;

int n,k;
int num[N];
int res[K][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    num[0] = 0;
    fill(num + 1, num + n, 1);
    int cur_pow = 1;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            if(j < cur_pow) res[i][j] = 0;
            else if(j < cur_pow * 2) res[i][j] = j - cur_pow;
            else res[i][j] = cur_pow * 2 - 1;
        }
        cur_pow *= 2;
    }
    for(int i = 0; i < k; i++) {
        for(int j = n - 1; j >= 0; j--) cout << n - res[i][j] << " ";
        cout << endl;
    }
}