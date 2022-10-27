#include <iostream>
#include <algorithm>
using namespace std;
int n,a[102];
int main(){
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int need=(int)(4.5*n + 0.6);
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(sum<need) {
            sum+=5-a[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}