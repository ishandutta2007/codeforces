#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;
int n , a[N][N];
char s[N][N];
int b[N] , c[N];
void work() {
    int i , j;
    scanf("%d" , &n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , s[i] + 1);
        for (j = 1 ; j <= n ; ++ j)
            a[i][j] = s[i][j] - '0';
    }
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &c[i]);
    vector<int> V;
    while (1) {

        for (i = 1 ; i <= n ; ++ i)
            if (b[i] == c[i])
                break;
        if (i > n)
            break;
        V.push_back(i);
        for (j = 1 ; j <= n ; ++ j)
            b[j] += a[i][j];
    }
    printf("%d\n" , V.size());
    for (i = 0 ; i < V.size() ; ++ i)
        printf("%d\n" , V[i]);
}

int main() {
    work();
    return 0;
}