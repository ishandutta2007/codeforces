#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, Max, ans;
int A[101010];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        Max = max(Max, A[i]);
    }
    int len=0;
    for (int i=1; i<=N; i++){
        if (A[i] == Max) len++, ans = max(ans, len);
        else len = 0;
    }
    printf("%d", ans);
    return 0;
}