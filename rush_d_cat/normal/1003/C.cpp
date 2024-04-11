#include <iostream>
using namespace std;
int k,n,a[5002];
int main(){
    scanf("%d%d",&n,&k);
    double ans=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=k;i<=n;i++){
        double sum=0;
        for(int j=1;j<=i;j++)sum+=a[j];
        ans=max(ans,sum/i);
        for(int j=i+1;j<=n;j++){
            sum+=a[j];
            sum-=a[j-i];
            ans=max(ans,sum/i);
        }
    }
    printf("%.8f\n", ans);
}