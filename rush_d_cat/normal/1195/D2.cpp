#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200000+10;
typedef long long LL;
const LL MOD=998244353;
int n,a[N],L[30]; LL p[30];
int count(int x){
    int len=0;
    while(x){
        len++; x/=10;
    }
    return len;
}
int main() {
    p[0]=1;
    for(int i=1;i<30;i++){
        p[i]=p[i-1]*10%MOD;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        L[count(a[i])]++;
    }
    //for(int i=1;i<=3;i++)printf("#%d\n", L[i]);
    LL ans=0;
    for(int i=1;i<=n;i++){
        int l=count(a[i]);
         LL tmp[20]={0}, v=a[i];
         for(int j=0;j<l;j++){
            tmp[j]=v%10; v/=10;
         }
         for(int j=1;j<=l;j++){
            LL v=0;
            for(int k=0;k<j;k++){
                v=v+p[2*k+1]*tmp[k];
                v%=MOD;
            }
            for(int k=j;k<l;k++){
                v=v+p[2*j + (k-j)]*tmp[k];
                v%=MOD;
            }
            //printf("i=%d,j=%d,v=%d\n", i,j,v);
            if(j==l){
                LL sum=0;
                for(int k=j;k<=10;k++) sum+=L[k];
                ans=ans+v*sum%MOD; ans=ans%MOD;
                continue;
            }
            ans=ans+v*L[j]%MOD; ans=ans%MOD;
         }
    }
    //cout << ans << endl;
    LL tmp=ans;
    for(int i=1;i<=n;i++){
        int l=count(a[i]);
         LL tmp[20]={0}, v=a[i];
         for(int j=0;j<l;j++){
            tmp[j]=v%10; v/=10;
         }
         for(int j=1;j<=l;j++){
            LL v=0;
            for(int k=0;k<j;k++){
                v=v+p[2*k]*tmp[k];
                v%=MOD;
            }
            for(int k=j;k<l;k++){
                v=v+p[2*j + (k-j)]*tmp[k];
                //printf("%d * %d\n", p[2*j+(k-j)],tmp[j]);
                v%=MOD;
            }
            //printf("# i=%d,j=%d,v=%d,l=%d\n", i,j,v,l);
            if(j==l){
                LL sum=0;
                for(int k=j;k<=10;k++) sum+=L[k];
                ans=ans+v*sum%MOD; ans=ans%MOD;
                continue;
            }
            ans=ans+v*L[j]%MOD; ans=ans%MOD;
         }
    }
    //cout<<ans-tmp<<endl;
    cout<<ans<<endl;
}