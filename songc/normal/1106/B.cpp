#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, M, p=1;
LL ans, C[101010], A[101010];
LL R[101010];

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    for (int i=1; i<=N; i++) scanf("%lld", &C[i]);
    for (int i=1; i<=N; i++) R[i] = i;
    sort(R+1, R+N+1, [&](int i, int j){
        if (C[i] == C[j]) return i < j;
        return C[i] < C[j];
    });
    int k, cnt;
    for (int i=1; i<=M; i++){
        scanf("%d %d", &k, &cnt);
        ans = 0;
        if (A[k] >= cnt){
            A[k] -= cnt;
            ans = cnt * C[k];
            cnt = 0;
        }
        else{
            ans = A[k] * C[k];
            cnt -= A[k];
            A[k] = 0;
            while (p <= N){
                if (A[R[p]] >= cnt){
                    A[R[p]] -= cnt;
                    ans += cnt * C[R[p]];
                    cnt = 0;
                    break;
                }
                else{
                    ans += A[R[p]] * C[R[p]];
                    cnt -= A[R[p]];
                    A[R[p]] = 0;
                    p++;
                }
            }
        }
        if (cnt) printf("0\n");
        else printf("%lld\n", ans);
    }
    return 0;
}