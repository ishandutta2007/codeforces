#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, A[20];

bool f(int k, int deg){
    if (k > N){
        if (deg == 0) return true;
        return false;
    }
    if (f(k+1, (deg+A[k])%360)) return true;
    return f(k+1, (deg-A[k]+360)%360);
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    if (f(1, 0)) puts("YES");
    else puts("NO");
    return 0;
}