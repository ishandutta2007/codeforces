/*
ID: Sfiction
OJ: CF
PROB: 449A
*/
#include <cstdio>

int main(){
    long long n,m,k;
    long long ans1,ans2;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if (n+m-2<k)
        printf("-1");
    else
        if (k<n || k<m){
            ans1=m*(n/(k+1));
            ans2=n*(m/(k+1));
            if (ans1<ans2)
                ans1=ans2;
            printf("%I64d",ans1);
        }
        else{
            ans1=ans2=-1;
            ans1=n/(k-m+2);
            ans2=m/(k-n+2);
            if (ans1<ans2)
                ans1=ans2;
            printf("%I64d",ans1);
        }
    return 0;
}