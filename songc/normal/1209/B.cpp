#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[110];
int cnt[3000];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%1d", &A[i]);
    for (int i=1; i<=N; i++){
        int a, b;
        scanf("%d %d", &a,&b);
        for (int j=0; j<=2600; j++){
            if (j >= b && (j-b)%a == 0) A[i] ^= 1;
            cnt[j] += A[i];
        }
    }
    for (int i=0; i<=2600; i++) ans = max(ans, cnt[i]);
    printf("%d", ans);
    return 0;
}