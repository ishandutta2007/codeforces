#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,a[3000],sum[3000];

void calc_sum(int t){
    if(t>=(1<<n))return;
    sum[t<<1]=sum[t]+a[t<<1];
    calc_sum(t<<1);
    sum[t<<1|1]=sum[t]+a[t<<1|1];
    calc_sum(t<<1|1);
}

int Max,ans;

int calc_min(int t){
    if(t>=(1<<n))return Max-sum[t];
    return min(calc_min(t<<1),calc_min(t<<1|1));
}

void solve(int t,int cur){
    int res=calc_min(t);
    ans+=res-cur;
    if(t>=(1<<n))return;
    solve(t<<1,res);
    solve(t<<1|1,res);
}

int main(){
    scanf("%d",&n);
    for(int i=2;i<(1<<n+1);++i)
        scanf("%d",a+i);
    calc_sum(1);
    for(int i=(1<<n);i<(1<<n+1);++i)
        Max=max(Max,sum[i]);
    solve(1,0);
    printf("%d\n",ans);
    return 0;
}