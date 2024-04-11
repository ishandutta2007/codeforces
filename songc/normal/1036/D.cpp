#include <bits/stdc++.h>
using namespace std;
typedef long  long LL;

int N, M, ans;
int A[303030], B[303030];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    scanf("%d", &M);
    for (int i=1; i<=M; i++) scanf("%d", &B[i]);

    int i, j;
    LL Asum=A[1], Bsum=B[1];
    for (i=1, j=1; i<=N && j<=M; ){
        if (Asum == Bsum){
            ans++, i++, j++;
            Asum=A[i], Bsum=B[j];
            continue;
        }
        if (Asum < Bsum){
            i++;
            Asum += A[i];
            continue;
        }
        else{
            j++;
            Bsum += B[j];
            continue;
        }
    }
    if (i <= N || j <= M) {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}