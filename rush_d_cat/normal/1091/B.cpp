#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int n;
int x[N],y[N];

int main(){
    scanf("%d",&n);
    LL sx=0,sy=0;
    for(int i=1;i<=2*n;i++){
        scanf("%d%d",&x[i],&y[i]);
        sx+=x[i], sy+=y[i];
    }
    sx/=n;sy/=n;
    printf("%lld %lld\n", sx,sy);
}