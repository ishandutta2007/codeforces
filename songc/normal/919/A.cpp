#include <bits/stdc++.h>
using namespace std;

int N, M;
double a, b, ans = 10101010;

int main(){
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        scanf("%lf %lf", &a, &b);
        ans = min(ans, a/b*M);
    }
    printf("%lf", ans);
    return 0;
}