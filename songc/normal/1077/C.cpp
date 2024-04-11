#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int ans[202020], cnt;
LL sum;
int A[202020];
map<LL, int> M;

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        M[A[i]]++;
        sum += A[i];
    }
    for (int i=1; i<=N; i++) {
        if ((sum-A[i]) & 1) continue;
        if ((sum-A[i])/2 == A[i]){
            if (M[(sum-A[i])/2] > 1) ans[cnt++] = i;
        }
        else if (M[(sum-A[i])/2]) ans[cnt++] = i;
    }
    printf("%d\n", cnt);
    for (int i=0; i<cnt; i++) printf("%d ", ans[i]);
    return 0;
}