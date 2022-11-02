#include <bits/stdc++.h>
using namespace std;

#define N 100010

int sz[N][3];
char s[N];

int main() {
    ///freopen("r.txt", "r", stdin);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
  ///  cout << n << endl;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == 'a') {
            sz[i][0] = sz[i-1][0] + 1;
            sz[i][2] = max(sz[i-1][1], sz[i-1][2]) + 1;
            sz[i][1] = sz[i-1][1];
        }
        else {
            sz[i][0] = sz[i-1][0];
            sz[i][2] = sz[i-1][2];
            sz[i][1] = max(sz[i-1][0], sz[i-1][1]) + 1;
        }
    }
    printf("%d\n", max(sz[n][0], max(sz[n][2], sz[n][1])));
}