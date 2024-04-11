#include <iostream>
#include <cstring>
using namespace std;
long long t, n1, n2, res, f[55][55];
char s1[25], s2[25];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s1+1 >> s2+1;
        res = 0;
        n1 = strlen(s1+1); n2 = strlen(s2+1);
        fill(f[0], f[n1+1], 0);
        for(int i=1; i<=n1; i++)
        for(int j=1; j<=n2; j++) {
            if (s1[i] == s2[j]) {
                f[i][j] = f[i-1][j-1] + 1;
                res = max(res, f[i][j]);
            }
        }
        cout << n1 + n2 - res*2 << '\n';
    }
}