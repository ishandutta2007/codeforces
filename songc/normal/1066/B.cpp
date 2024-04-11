#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, r;
int ans;
int A[1010];
bool H[1010];

int main(){
    scanf("%d %d", &N, &r);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<=N; i++){
        if (H[i]) continue;
        int t = 0;
        for (int j=max(i-r+1, 1); j<=min(i+r-1, N); j++) if (A[j]) t = j;
        if (!t){
            puts("-1");
            return 0;
        }
        ans++;
        for (int j=max(t-r+1, 1); j<=min(t+r-1, N); j++) H[j] = true;
    }
    printf("%d", ans);
    return 0;
}