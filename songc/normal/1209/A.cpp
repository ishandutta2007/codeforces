#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[110];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    sort(A+1, A+N+1);
    for (int i=1; i<=N; i++){
        if (!A[i]) continue;
        for (int j=i+1; j<=N; j++) if (A[j]%A[i] == 0) A[j] = 0;
        ans++;
    }
    printf("%d", ans);
    return 0;
}