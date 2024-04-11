#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    if(4 * a + 2 * b <= n) return !printf("1");
    if(2 * a + b <= n) return !printf("2");
    if((4*a <= n) || (b+a <= n && 3*a <= n) || (2*b <= n && 3*a <= n) || (2*a <= n && 2*b <= n)
       ||(b+a <= n && 2*a <= n)) return !printf("3");
    if(a+b <= n || (2*a <= n)) return !printf( "4");
    if(2 * b <= n) return !printf("5");
    return !printf("6");
}