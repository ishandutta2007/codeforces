#include <iostream>
using namespace std;

int n, a[152][152], b[152][152];

int main() {
    cin >> n;
    a[1][1]=1, b[1][0]=1;
    for (int i=1;i<n;i++) {
        for (int j=0;j<=n;j++) {
            b[i+1][j]=a[i][j];
            a[i+1][j]=b[i][j] + (j>=1?a[i][j-1]:0);
        }
    }

    printf("%d\n", n);
    for (int i=0;i<=n;i++) {
        printf("%d ", a[n][i]%2);
    }
    printf("\n");
    printf("%d\n", n-1);
    for (int i=0;i<=n-1;i++) {
        printf("%d ", b[n][i]%2);
    }

}