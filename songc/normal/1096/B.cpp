#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, S, E;
char str[202020];

int main(){
    scanf("%d", &N);
    scanf("%s", str+1);
    for (S=2; S<=N; S++){
        if (str[S] != str[S-1]){
            S--;
            break;
        }
    }
    for (E=2; E<=N; E++){
        if (str[N-E+1] != str[N-E+2]){
            E--;
            break;
        }
    }

    if (S == N) printf("%d\n", (LL)N * (N+1) % 998244353);
    else if (str[1] == str[N]) printf("%d\n", (LL)(S+1) * (E+1) % 998244353);
    else printf("%d\n", S+E+1);
    return 0;
}