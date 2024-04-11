#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int Q;
LL L, R;

vector<LL> S;

void f(LL K, int l, int d){
    if (d > 19) return;
    S.push_back(K);
    if (l < 3) for (int i=1; i<10; i++) f(K*10 + i, l+1, d+1);
    f(K*10, l, d+1);
}

int main(){
    scanf("%d", &Q);
    for (int i=1; i<10; i++) f(i, 1, 1);
    sort(S.begin(), S.end());
    for (int q=0; q<Q; q++) {
        scanf("%I64d %I64d", &L, &R);
        printf("%d\n", (upper_bound(S.begin(), S.end(), R) - lower_bound(S.begin(), S.end(), L)));
    }
    return 0;
}