#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5;

int main()
{
    ll i,j,k,x,y,z,n,m,a,b,c;
    scanf("%I64d %I64d", &n, &k);
    if(n>=k-1) {
        if(k%2==0) k--;
        printf("%I64d\n", k/2);
        return 0;
    }
    else if(k-n>=n) {
        puts("0");
        return 0;
    }
    else {
        a=k-n;
        printf("%I64d\n", (n-a+1)/2);
        return 0;
    }
}