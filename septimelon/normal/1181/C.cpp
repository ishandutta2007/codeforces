#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c[1000][1001];
    int n, m;
    long long cou = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    for (int i = 0; i < n; i++)
        c[i][m] = '-';
    int indl, indr;
    int len;
    bool brea;
    //for (int len = 1; len < n; len++) {
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m; j++) {
                indl = j;
                indr = j+1;
                brea = false;
                len = 1;
                while (i+len*3 <= n && c[i+len][j] == c[i][j])
                    len++;
                if (i+len*3 > n)
                    continue;
                for (int r = 0; r < 3*len; r += len) {
                    for (int q = 1; q < len; q++)
                        if (c[i+r+q][j] != c[i+r][j])
                            brea = true;
                }
                if (c[i+len][j] == c[i][j] || c[i+len][j] == c[i+2*len][j])
                    brea = true;
                if (brea) continue;
                while (true) {
                    for (int q = 0; q < len*3; q++) {
                        if (c[i+q][j] != c[i+q][indr]) {
                            brea = true;
                            break;
                        }
                    }
                    if (brea) break;
                    indr++;
                }
                j = indr-1;
                //cout << i << " " << indl << " " << indr << endl;
                cou += (long long) (indr-indl)*(indr-indl+1)/2;
            }
        }
    //}
    cout << cou << endl;
    return 0;
}