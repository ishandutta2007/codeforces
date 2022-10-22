#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

LL t , a , b , B;
LL dig[N] , len , res;
void work() {
    cin >> t >> a >> b;
    B = b;
    if (t == 1 && a == 1) {
        if (b == 1)
            printf("inf\n");
        else
            printf("0\n");
            return;
    }
    if(t == 1) {
        if (b == 1) {
            printf("0\n");
            return;
        }
        while(b % a == 0)
            b /= a;
        if (b == 1) {
            printf("1\n");
            return;
        }
    }
    if(a > 1) {
        while(b) {
            dig[len ++] = b % a;
            b /= a;
        }
        LL s = 0;
        for(int i = len - 1 ; i >= 0 ; -- i) {
            s *= t;
            s += dig[i];
        }
        if(s == a)
            ++ res;
    }
    if(a == B)
        ++ res;
    printf("%I64d\n" , res);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}