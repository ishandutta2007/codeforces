#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, M, t;
int P[40];

int main(){
    int ret;
    scanf("%d %d", &N, &M);
    for (t=0; t<M; t++){
        printf("%d\n", N);
        fflush(stdout);
        scanf("%d", &P[t]);
        if (P[t] == 0) return 0;
        P[t] *= -1;
    }
    int L = 1, H = N, t = 0;
    while (L <= H){
        int mid = (L+H)/2;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("%d", &ret);
        if (ret*P[t] == -1) H = mid-1;
        else if (ret*P[t] == 1) L = mid+1;
        else return 0;
        t++;
        t %= M;
    }
    return 0;
}