#include <bits/stdc++.h>
using namespace std;

int N, A, B;
int D[2010101], a[2010101], b[2010101];

int main() {
    int num = 1;
    scanf("%d %d %d", &N, &A, &B);
    D[0] = 1;
    for (int i=0; i<=N; i++){
        if (D[i]){
            D[i+A] = 1;
            a[i+A] = a[i] + 1;
            b[i+A] = b[i];

            D[i+B] = 1;
            a[i+B] = a[i];
            b[i+B] = b[i] + 1;
        }
    }
    if (!D[N]){
        puts("-1");
        return 0;
    }
    for (int i=0; i<a[N]; i++){
        for (int j=1; j<A; j++) printf("%d ", num+j);
        printf("%d ", num);
        num += A;
    }
    for (int i=0; i<b[N]; i++){
        for (int j=1; j<B; j++) printf("%d ", num+j);
        printf("%d ", num);
        num += B;
    }
    return 0;
}