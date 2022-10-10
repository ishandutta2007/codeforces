#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k, row[1001], col[1001], a[1001][1001];
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
    
    for (int i=1; i<=n; i++)
        row[i] = i;
    for (int j=1; j<=m; j++)
        col[j] = j;
    for (int j=0; j<k; j++) {
        char s;
        int x, y;
        cin >> s >> x >> y;
        if (s == 'c')
            swap(col[x], col[y]);
        else if (s == 'r')
            swap(row[x], row[y]);
        else
            cout << a[row[x]][col[y]] << "\n";
    }
    
    return 0;
}