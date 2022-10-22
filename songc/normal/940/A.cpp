#include <bits/stdc++.h>
using namespace std;

int N, d;
int ans;
int p[110];

int main() {
    int a;
    scanf("%d %d", &N, &d);
    for (int i=0; i<N; i++) {
        scanf("%d", &a);
        p[a]++;
    }
    for (int i=0; i<=100-d; i++){
        a=0;
        for (int j=0; j<=d; j++) a += p[i+j];
        ans = max(ans, a);
    }
    printf("%d", N-ans);
    return 0;
}