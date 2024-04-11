#include<stdio.h>
#define mod 1000000007
#define N 1010000

typedef long long ll;

ll f[N];

int main(){
    //freopen("1.in", "r", stdin);
    int p, k;
    scanf("%d%d", &p, &k);
    f[0] = 1;
    for(int i=1; i<p; i++)f[i] = 1ll*f[i-1]*k%p;
    int cnt;
    int po;
    if(k>1){
        for(int i=1; i<p; i++)if(f[i] == 1){cnt = i;break;}
        po = (p-1)/cnt;
    }else if(k==1){po = p;}
else po = p-1;

    f[0] = 1;
    for(int i=1; i<=po; i++)f[i] = 1ll*f[i-1]*p%mod;
    printf("%I64d\n", f[po]);
    return 0;
}