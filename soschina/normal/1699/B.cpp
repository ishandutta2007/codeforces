#include <cstdio>
using namespace std;
const int N = 52;

int t, n, m, a[N][N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        bool now = 0;
        for (int i = 1; i <= n; i += 2){
            now ^= 1;
            bool nownow = now;
            for (int j = 0; j <= m; j += 2){
                nownow ^= 1;
                a[i][j] = a[i][j + 1] = nownow;
            }
            nownow = now ^ 1;
            for (int j = 0; j <= m; j += 2){
                nownow ^= 1;
                a[i + 1][j] = a[i + 1][j + 1] = nownow;
            }

        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++)
                printf("%d ", a[i][j]);
            putchar('\n');
        }
    }
    return 0;
}