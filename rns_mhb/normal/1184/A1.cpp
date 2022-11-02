#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll r;
    scanf("%I64d", &r);
    r --;
    if(r < 4 || (r & 1)) return puts("NO"), 0;
    printf("1 %I64d\n", r-2>>1);
}