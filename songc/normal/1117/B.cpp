#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL M, K, ans;
LL Max, Max2;

int main(){
    LL a;
    scanf("%d %lld %lld", &N, &M, &K);
    for (int i=1; i<=N; i++){
        scanf("%lld", &a);
        if (Max <= a) Max2 = Max, Max = a;
        else if (Max2 < a) Max2 = a;
    }
    printf("%lld\n", M/(K+1)*(K*Max + Max2) + M%(K+1)*Max);
    return 0;
}