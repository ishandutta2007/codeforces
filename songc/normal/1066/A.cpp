#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int L, v, l, r;

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d %d %d %d", &L, &v, &l, &r);
        printf("%d\n", (L/v)-(r/v)+((l-1)/v));
    }
    return 0;
}