#include <cstdio>
#define ll long long
int a[300005],b[300005];
int main(){
    int n,m;
    ll sum_1=0,sum_2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum_1+=a[i];
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        sum_2+=b[i];
    }
    if(sum_1!=sum_2){
        return puts("-1"),0;
    }
    sum_1=a[1],sum_2=b[1];
    int i=2,j=2;
    int ans=0;
    while(i<=n&&j<=m){
        if(sum_1==sum_2){
            ans++;
            sum_1=a[i];
            sum_2=b[j];
            i++,j++;
        }
        else if(sum_1<sum_2){
            sum_1+=a[i];
            i++;
        }
        else{
            sum_2+=b[j];
            j++;
        }
    }
    ans++;
    printf("%d\n",ans);
    return 0;
}