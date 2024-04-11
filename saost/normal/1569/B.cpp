#include <iostream>
using namespace std;
int t, n, cnt, Q[55], nxt[55];
char s[55], a[55][55];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cnt = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) a[i][j] = 'O';
            a[i][i] = 'X';
            a[i][n] = '\0';
        }
        for(int i=0; i<n; ++i) if (s[i] == '2') Q[++cnt] = i;
        if (0 < cnt && cnt < 3) cout << "NO\n";
        else {
            cout << "YES\n";
            Q[cnt + 1] = Q[1];
            for(int i=1; i<=cnt; ++i) nxt[Q[i]] = Q[i+1];
            for(int i=0; i<n; ++i) {
                if (s[i] == '1') {
                    for(int j=0; j<n; ++j) if (i != j) a[i][j] = a[j][i] = '=';
                }
                else {
                    a[i][nxt[i]] = '+'; a[nxt[i]][i] = '-';
                    for(int j=0; j<n; ++j) if (a[i][j] == 'O') {
                        a[i][j] = '+'; a[j][i] = '-';
                    }
                }
            }
            for(int i=0; i<n; ++i) cout << a[i] << '\n';
        }
    }
}