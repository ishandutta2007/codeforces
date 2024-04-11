#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n,m;
int a[N], b[N];
int res[N][N];

int main() {
    cin >> n >> m;
    int xa = 0, xb = 0;
    for(int i = 0; i < n; i++) cin >> a[i], xa ^= a[i];
    for(int i = 0; i < m; i++) cin >> b[i], xb ^= b[i];
    if(xa != xb) return !printf("NO");
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++) res[i][j] = (1 << 30) - 1;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            if(j != m-1) a[i] ^= res[i][j];
            else res[i][j] = a[i];
        }
    }
    for(int j = 0; j < m-1; j++){
        for(int i = 0; i < n; i++){
            if(i != n-1) b[j] ^= res[i][j];
            else res[i][j] = b[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == n-1 && j == m-1) res[i][j] = xa;
            else xa ^= res[i][j];
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << res[i][j] << " ";
        cout << endl;
    }
//    for(int j = 0; j < m; j++){
//        int now = 0;
//        for(int i = 0; i < n; i++) now ^= res[i][j];
//        cout << now << " ";
//    }
}