#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int A[101010];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=2*N; i++) scanf("%d", &A[i]);
    sort(A+1, A+2*N+1);
    if (A[1] == A[2*N]) printf("-1");
    else for (int i=1; i<=2*N; i++) printf("%d ", A[i]);
    return 0;
}