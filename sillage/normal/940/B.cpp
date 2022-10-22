#include<cstdio>
int n,k,a,b;
long long ans;
int main(){
    scanf("%d%d%d%d",&n,&k,&a,&b);
    while (n>1){
        if (n%k==0){
            long long ca=1LL*a*(n-(n/k));
            if (ca>b){
                ans+=b;
                n/=k;
            }else{
                ans+=1LL*(n-1)*a;
                break;
            }
        }else{
            if (n>k){
                ans+=1LL*(n%k)*a;
                n-=n%k;
            }else{
                ans+=1LL*(n-1)*a;
                n=1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}