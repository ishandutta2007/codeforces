#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
LL L, R;
LL cnt[3];
LL D[202020][3];

int main(){
    scanf("%d %lld %lld", &N, &L, &R);
    D[0][0] = 1;
    cnt[0] = (R/3) - ((L-1)/3);
    cnt[1] = ((R+2)/3) - ((L+1)/3);
    cnt[2] = ((R+1)/3) - (L/3);
    for (int i=0; i<N; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                D[i+1][(j+k)%3] = (D[i+1][(j+k)%3] + (D[i][j] * cnt[k])) % MOD;
            }
        }
    }
    printf("%lld\n", D[N][0]);
    return 0;
}