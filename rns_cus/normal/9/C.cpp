//
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long p[1<<13];
long long POW(long long x, int y){
    if(!y)return 1;
    long long r = POW(x,y/2);
    if(y & 1)return r * r * x;
    return r * r;
}
int main(){
    long long  n;
    for(int i = 0; i < (1<<13); i ++){
        int ii = i;
        long long k = 0ll;
        for(int j = 0; j < 13; j ++){
            k += 1ll * POW(10, j) * (ii % 2);
            ii /= 2;
        }
        p[i] = k;
    }
    while(scanf("%I64d", &n) ==1){
        int st = upper_bound(p,p + (1<<13),n ) - p;
        printf("%d\n", st-1);
    }
    return 0;

}