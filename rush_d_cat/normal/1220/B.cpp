#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1000 + 10;
int n,a[N][N];
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
LL x[N];
void chk(int val) {
    x[1] = val;
    for(int i=2;i<=n;i++)
        x[i] = a[1][i] / val;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[i] * x[j] != a[i][j]) return;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ", x[i]);
    exit(0);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int g = a[1][2];
    for(int i=1;i<=n;i++){
        g = gcd(g, a[1][i]);
    }
    for(int d=1;d*d<=g;d++) {
        if(g%d==0) {
            chk(d);
            chk(g/d);
        }
    }
}