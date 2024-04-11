#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, q, rowVals[500], a[500][500];
    multiset<int, greater<int>> ret;
    cin >> n >> m >> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];
    
    for (int c=0; c<q; c++) {
        int i, j;
        cin >> i >> j;
        a[i-1][j-1] ^= 1;
        if (c == 0)
            for (int k=0; k<n; k++) {
                rowVals[k] = 0;
                int acc = 0;
                for (int l=0; l<m; l++) {
                    if (a[k][l] == 1)
                        acc++;
                    else {
                        rowVals[k] = max(rowVals[k], acc);
                        acc = 0;
                    }
                }
                rowVals[k] = max(rowVals[k], acc);
                ret.insert(rowVals[k]);
            }
        else {
            ret.erase(ret.find(rowVals[i-1]));
            rowVals[i-1] = 0;
            int acc = 0;
            for (int l=0; l<m; l++) {
                if (a[i-1][l] == 1)
                    acc++;
                else {
                    rowVals[i-1] = max(rowVals[i-1], acc);
                    acc = 0;
                }
            }
            rowVals[i-1] = max(rowVals[i-1], acc);
            ret.insert(rowVals[i-1]);
        }
        cout << *ret.begin() << endl;
    }
    
    return 0;
}