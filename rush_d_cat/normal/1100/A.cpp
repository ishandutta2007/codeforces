#include <iostream>
#include <cmath>
using namespace std;
const int N=102;
int n,k,a[N];
int main(){
    scanf("%d%d",&n,&k);
    int d1=0,d2=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) d1++; else d2++;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        int c1=d1,c2=d2;
        for(int j=i;j<=n;j+=k){
            if(a[j]==1) c1--; else c2--;
        }
        ans=max(ans,abs(c1-c2));
    }
    cout<<ans<<endl;
}