#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, ans;
int A[110];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=2; i<N; i++) if (A[i-1] && !A[i] && A[i+1]) A[i+1] = 0, ans++;
    printf("%d", ans);
    return 0;
}