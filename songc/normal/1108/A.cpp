#include <bits/stdc++.h>
using namespace std;

int Q;
int L1, R1, L2, R2;

int main(){
    scanf("%d", &Q);
    while (Q--){
        scanf("%d %d %d %d", &L1, &R1, &L2, &R2);
        if (L1 == L2) L2++;
        printf("%d %d\n", L1, L2);
    }
    return 0;
}