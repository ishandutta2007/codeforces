#include <bits/stdc++.h>
using namespace std;

const int N = 5005, Q = (int)1e5 + 500;

int n,q,a,b;
int num[N], dsum[N][N], res[N][N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j+i < n; j++){
            dsum[j][j+i] = (i == 0 ? num[j] : dsum[j][j+i-1] ^ dsum[j+1][j+i]);
            res[j][j+i] = (i == 0 ? num[j] : max(dsum[j][j+i], max(res[j][j+i-1], res[j+1][j+i])));
        }
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &a, &b);
        a--, b--;
        printf("%d\n", res[a][b]);
    }
}