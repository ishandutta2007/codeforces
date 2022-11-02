//E
#include<cstdio>
#include<algorithm>
using namespace std;

int n, mod;

int main(){
    scanf("%d", &n);
    mod = n - 1;
    for(int i = 0; i < n; i ++)for(int j = 0; j < n; j ++) printf("%d%c",i==j?0:i<(n-1)and j<(n-1)?mod-(mod-(i+j)%mod)%mod:mod-(mod-min(i,j)*2%mod)%mod,j<(n-1)?32:10);
}