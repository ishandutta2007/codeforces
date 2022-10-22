#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, Q;
int A[202020];
vector<pii> V;

int main(){
    LL x;
    scanf("%d %d", &N, &Q);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<N; i++){
        V.push_back(pii(A[i], A[i+1]));
        if (A[i] > A[i+1]) swap(A[i], A[i+1]);
        A[N+i] = A[i];
    }
    while (Q--){
        scanf("%lld", &x);
        if (x < N) printf("%d %d\n", V[x-1].first, V[x-1].second);
        else{
            x %= N-1;
            if (x) printf("%d %d\n", A[N], A[N+x]);
            else printf("%d %d\n", A[N], A[2*N-1]);
        }
    }
    return 0;
}