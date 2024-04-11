#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int Q;
LL N, d;

int main(){
    scanf("%d", &Q);
    while (Q--){
        scanf("%lld", &N);
        d = 0;
        while ((1ll<<d) <= N) d++;
        if ((1ll<<d)-1 == N){
            bool tf = true;
            for (LL i=2; i*i<=((1ll<<d)-1); i++){
                if (((1ll<<d)-1)%i == 0){
                    printf("%lld\n", ((1ll<<d)-1)/i);
                    tf = false;
                    break;
                }
            }
            if (tf) printf("1\n");
        }
        else printf("%lld\n", (1ll<<d)-1);
    }
    return 0;
}