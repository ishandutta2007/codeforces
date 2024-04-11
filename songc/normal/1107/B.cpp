#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int TC, K;
LL N;

int main(){
    scanf("%d", &TC);
    while (TC--){
        scanf("%lld %d", &N, &K);
        printf("%lld\n", 9*(N-1) + K);
    }
    return 0;
}