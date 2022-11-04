#include <cstdio>
using namespace std;
const int N = 350;

int n, a[N][N];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i][i]);
        for (int j = i - 1; j >= 0; j--)
            a[i][j] = (a[i][j + 1] - i + n) % n;
        for (int j = i + 1; j < n; j++)
            a[i][j] = (a[i][j - 1] + i) % n;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        putchar('\n');
    }
    return 0;
}