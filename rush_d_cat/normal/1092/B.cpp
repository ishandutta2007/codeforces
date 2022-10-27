#include <iostream>
#include <algorithm>
using namespace std;
const int N=200000+10;

int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i+=2){
        ans+=a[i+1]-a[i];
    }
    cout<<ans<<endl;
}