#include <iostream>
using namespace std;
typedef long long LL;
int n; LL k;
LL f[52],a[52];
int main() {
    f[0]=1; f[1]=1; f[2]=2;
    for(int i=3;i<=50;i++){
        f[i]=f[i-2]*2 + f[i-3];
        //printf("f[%d]=%lld\n", i,f[i]);
    }
    for(int i=1;i<=50;i++)a[i]=i;

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int len=n-i;        
        if(f[len]<k){
            k-=f[len]; swap(a[i],a[i+1]); ++i;
        } 
    }
    for(int i=1;i<=n;i++) printf("%lld ", a[i]);
}