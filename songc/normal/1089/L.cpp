#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, K;
LL ans;
int A[101010], B[101010];
int match[101010];
vector<int> V;

int main(){
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<=N; i++) scanf("%d", &B[i]);
    for (int i=1; i<=N; i++){
        if (!match[A[i]]) match[A[i]] = B[i];
        else {
            if (match[A[i]] > B[i]) V.push_back(B[i]);
            else {
                V.push_back(match[A[i]]);
                match[A[i]] = B[i];
            }
        }
    }
    sort(V.begin(), V.end());
    int j=0;
    for (int i=1; i<=K; i++){
        if (!match[i]) {
            match[i] = V[j++];
            ans += match[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}