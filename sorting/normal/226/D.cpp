#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 3;

int a[N][N], n, m;
bool row[N], col[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];

    while(true){
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            int sum = 0;
            for(int j = 1; j <= m; ++j)
                sum += (row[i] ^ col[j]) ? -a[i][j] : a[i][j];
            if(sum < 0){
                ok = false;
                row[i] = !row[i];
            }
        }

        for(int j = 1; j <= m; ++j){
            int sum = 0;
            for(int i = 1; i <= n; ++i)
                sum += (row[i] ^ col[j]) ? -a[i][j] : a[i][j];
            if(sum < 0){
                ok = false;
                col[j] = !col[j];
            }
        }

        if(ok) break;
    }

    int row_cnt = 0;
    for(int i = 1; i <= n; ++i)
        row_cnt += row[i];
    cout << row_cnt << " ";
    for(int i = 1; i <= n; ++i)
        if(row[i])
            cout << i << " ";
    cout << "\n";

    int col_cnt = 0;
    for(int i = 1; i <= m; ++i)
        col_cnt += col[i];
    cout << col_cnt << " ";
    for(int i = 1; i <= m; ++i)
        if(col[i])
            cout << i << " ";
    cout << "\n";
}