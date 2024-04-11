#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, G, ans;
int A[303030];
vector<int> P;
map<int, int> M;

int main(){
    scanf("%d", &N);
    scanf("%d", &A[1]);
    G = A[1];
    for (int i=2; i<=N; i++){
        scanf("%d", &A[i]);
        G = __gcd(A[i], G);
    }
    for (int i=1; i<=N; i++) A[i] /= G;

    for (int i=2; i<4000; i++){
        bool tf = true;
        for (int j=2; j*j<=i; j++) if (i % j == 0) tf = false;
        if (tf) P.push_back(i);
    }

    for (int i=1; i<=N; i++){
        int T = A[i];
        for (int j=0; j<(int)P.size(); j++){
            if (T % P[j] == 0){
                M[P[j]]++;
                while (T % P[j] == 0) T /= P[j];
            }
        }
        if (T != 1) M[T]++;
    }

    for (auto it: M) ans = max(ans, it.second);
    if (!ans){
        puts("-1");
        return 0;
    }
    printf("%d", N-ans);
    return 0;
}