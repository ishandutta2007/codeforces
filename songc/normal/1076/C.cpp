#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
double N;

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%lf", &N);
        if (N && N<4) {
            puts("N");
            continue;
        }
        double k = sqrt(N*(N-4));
        if (k > N){
            puts("N");
            continue;
        }
        printf("Y %.10f %.10f\n", (N-k)/2, (N+k)/2);
    }
    return 0;
}