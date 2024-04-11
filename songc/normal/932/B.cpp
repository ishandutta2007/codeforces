#include <bits/stdc++.h>
using namespace std;

int Q;
int D[1010101];
int arr[10][1010101];

int f(int X){
    if (X <= 0) return 1;
    if (X%10) return f(X/10) * (X%10);
    else return f(X/10);
}

int g(int X){
    if (D[X]) return D[X];
    if (X < 10) return D[X] = X;
    return D[X] = g(f(X));
}

int main() {
    int l, r, k;
    scanf("%d", &Q);
    for (int i=1; i<=1000000; i++){
        k = g(i);
        for (int j=1; j<10; j++) arr[j][i] = arr[j][i-1];
        arr[k][i]++;
    }
    for (int q=0; q<Q; q++){
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", arr[k][r] - arr[k][l-1]);
    }
    return 0;
}