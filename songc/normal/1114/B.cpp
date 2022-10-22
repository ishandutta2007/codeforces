#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M, K;
int A[202020];
LL ans;
multiset<int> S;

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        S.insert(A[i]);
    }
    for (int i=1; i<=N-M*K; i++) S.erase(S.begin());
    for (int it : S) ans += it;
    printf("%lld\n", ans);
    int cnt = 0;
    for (int i=1; i<=N && K>1; i++){
        if (S.find(A[i]) != S.end()){
            cnt++;
            S.erase(S.find(A[i]));
            if (cnt >= M) {
                printf("%d ", i);
                cnt=0, K--;
            }
        }
    }
    return 0;
}