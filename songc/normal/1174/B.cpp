#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
bool odd, even;
int A[101010];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        if (A[i] & 1) odd = true;
        else even = true;
    }
    if (odd && even) sort(A+1, A+N+1);
    for (int i=1; i<=N; i++) printf("%d ", A[i]);
    return 0;
}