#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, K;
LL A[202020], ans;
char str[202020];
vector<LL> S;

int main(){
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    scanf("%s", str+1);
    for (int i=1; i<=N+1; i++){
        if (str[i] != str[i-1]){
            sort(S.begin(), S.end(), greater<LL>());
            for (int j=0; j<min((int)S.size(), K); j++) ans += S[j];
            S.clear();
        }
        S.push_back(A[i]);
    }
    printf("%lld\n", ans);
    return 0;
}