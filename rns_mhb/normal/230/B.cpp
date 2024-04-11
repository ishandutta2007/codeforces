#include<bits/stdc++.h>
using namespace std;

#define N 1000010
bool p[N];

int main() {
    int i, j, n, r;
    long long m;
    p[0] = p[1] = 1;
    for(i = 2; i < 1010; i ++) if(!p[i]) for(j = i * i; j < N; j += i) p[j] = 1;
    scanf("%d", &n);
    while(n --) {
        scanf("%I64d", &m);
        r = (int)sqrt(m);
        if(!p[r] && m == 1ll* r * r) puts("YES");
        else puts("NO");
    }
}