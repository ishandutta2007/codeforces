#include <cstdio>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int t, n, x;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int d = 0;
        for (int i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            d = gcd(d, x);
        }
        if(d == 1){
            puts("0");
            continue;
        }
        if(gcd(d, n) == 1)
            puts("1");
        else if(gcd(d, n - 1) == 1)
            puts("2");
        else
            puts("3");
    }
    return 0;
}