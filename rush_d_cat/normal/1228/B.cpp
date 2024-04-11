#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

LL mpow(LL a, LL x){ 
    if (x == 0) return 1;
    LL t = mpow(a, x>>1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD; 
}


const int N = 1002;
int h,w;
int b[N][N],W[N][N];
int r[N],c[N];
int main() {
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++) {
        scanf("%d", &r[i]);
        for(int j=1;j<=r[i];j++) b[i][j]=1;
    }
    for(int i=1;i<=w;i++) {
        scanf("%d", &c[i]);
        for(int j=1;j<=c[i];j++) b[j][i]=1;
    }


    for(int i=1;i<=h;i++){
        int pos=1;
        while(pos <= w && b[i][pos] == 1) pos ++;
        if (pos != r[i] + 1) return !printf("0\n");
        W[i][pos] = 1;
    }

    for(int i=1;i<=w;i++){
        int pos=1;
        while(pos <= h && b[pos][i] == 1) pos ++;
        if (pos != c[i] + 1) return !printf("0\n");
        W[pos][i] = 1;
    }

    int cnt = 0;
    for (int i=1;i<=h;i++) for(int j=1;j<=w;j++)
        if (W[i][j] == 0 && b[i][j] == 0) cnt ++;

    printf("%lld\n", mpow(2, cnt));
}