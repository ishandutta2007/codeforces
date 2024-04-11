#include <iostream>
#include <algorithm>
//#include <cmath.h>

using namespace std;

int main()
{
    long long int n,m,sum1=0,sum2=0;
    cin >> n >> m;
    long long int a[n+1],b[n+1];
    for(long long int i=0;i<n;i++){
        cin >> a[i];
    }
    a[n]=m;
    b[0]=a[0];
    for(long long int i=1;i<n+1;i++){
        b[i]=a[i]-a[i-1];
    }
    for(long long int i=1;i<=n;i+=2){
        sum2+=b[i];
    }
    long long int ans =0;
    for(long long int i=0;i<=n;i+=1){
        if(a[i+1]-a[i] > 1 && i%2 == 0) ans=max(ans,sum1+b[i]+sum2-1);
        if(a[i+1]-a[i] > 1 && i%2 == 1) ans=max(ans,sum1+sum2-1);
        if(i%2 == 0) sum1+=b[i];
        if(i%2 == 1) sum2-=b[i];

    }
    ans=max(ans,sum1);
    cout << ans<<endl;
    return 0;
}