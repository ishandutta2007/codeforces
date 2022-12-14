#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll f[100];
int n;

void prepare(){
    f[0]=1;
    for(int i=1;i<=10;i++) f[i]=f[i-1]*10;
}

long long calc(int n){
    int x=0;
    while(f[x]<=n) x++;
    x--;
    long long res=0;
    for(int i=1;i<=x;i++) res+=1ll*i*9*f[i-1];
    res+=1ll*(n-f[x]+1)*(x+1);
    return res;
}

int main() {
   /// freopen("b.in","r",stdin);
    prepare();
    scanf("%d",&n);
    printf("%I64d\n",calc(n));
}