#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 55;
int n , m;
char s[N][N];

void work() {
    int i , j;
    scanf("%d%d" , &n ,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    int res = 0;
    for (i = 1 ; i < n ; ++ i)
        for (j = 1 ; j < m ; ++ j) {
            char q[5] = {} , w = 0;
            q[w ++] = s[i][j];
            q[w ++] = s[i + 1][j];
            q[w ++] = s[i][j + 1];
            q[w ++] = s[i + 1][j + 1];
            sort(q , q + 4);
            q[4] = 0;
            if (strcmp(q , "acef") == 0)
                ++res;
        }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}