#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int Y, B, R;

int main(){
    scanf("%d %d %d", &Y, &B, &R);
    if (Y+1 <= B && Y+2 <= R) printf("%d\n", Y*3 + 3);
    else if (B-1 <= Y && B+1 <= R) printf("%d\n", B*3);
    else printf("%d\n", R*3 - 3);
    return 0;
}