#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, G=1;

int main(){
    scanf("%d", &N);
    while (N>3){
        for (int i=0; i<(N+1)/2; i++) printf("%d ", G);
        G *= 2;
        N /= 2;
    }
    if (N==3) printf("%d %d %d ", G, G, G*3);
    else if (N==2) printf("%d %d ", G, G*2);
    else printf("%d ", G);
    return 0;
}