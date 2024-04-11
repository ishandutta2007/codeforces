#include <bits/stdc++.h>

using namespace std;

const int k_N = 300 + 3;

int a[k_N][k_N];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int cnt = !(i == 0) + !(i == n - 1) + !(j == 0) + !(j == m - 1);
            if(a[i][j] > cnt){
                cout << "NO\n";
                return;
            }
            a[i][j] = cnt;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}