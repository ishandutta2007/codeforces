#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, ans;
int A[101010];

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(A, A+N);
    for (int i=1; i<N; i++) ans += A[i] - A[i-1] - 1;
    printf("%d", ans);
    return 0;
}