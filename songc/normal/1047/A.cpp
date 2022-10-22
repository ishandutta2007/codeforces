#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, K;

int main(){
    scanf("%d", &N);
    K = (N / 9) * 3;
    if (N % 9 == 0) printf("%d %d %d", K-1, K-1, K+2);
    if (N % 9 == 1) printf("%d %d %d", K-1, K+1, K+1);
    if (N % 9 == 2) printf("%d %d %d", K-1, K+1, K+2);
    if (N % 9 == 3) printf("%d %d %d", K+1, K+1, K+1);
    if (N % 9 == 4) printf("%d %d %d", K+1, K+1, K+2);
    if (N % 9 == 5) printf("%d %d %d", K+1, K+2, K+2);
    if (N % 9 == 6) printf("%d %d %d", K+2, K+2, K+2);
    if (N % 9 == 7) printf("%d %d %d", K+1, K+2, K+4);
    if (N % 9 == 8) printf("%d %d %d", K+2, K+2, K+4);
    return 0;
}