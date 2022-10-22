#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
char str[101010];
LL H, A, R, D;
LL C[101010];

int main(){
    scanf("%d", &N);
    scanf("%s", str+1);
    A = R = D = 12345678901234;
    for (int i=1; i<=N; i++) scanf("%lld", &C[i]);
    for (int i=1; i<=N; i++){
        if (str[i] == 'h'){
            A = min(A, H);
            H += C[i];
        }

        if (str[i] == 'a'){
            R = min(R, A);
            A += C[i];
        }

        if (str[i] == 'r'){
            D = min(D, R);
            R += C[i];
        }

        if (str[i] == 'd'){
            D += C[i];
        }
    }
    printf("%lld\n", min(min(H, A), min(R, D)));
    return 0;
}