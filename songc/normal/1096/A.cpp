#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T, N;

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d %*d", &N);
        printf("%d %d\n", N, 2*N);
    }
    return 0;
}