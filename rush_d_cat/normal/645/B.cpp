#include <iostream>
using namespace std;
typedef long long LL;
LL n,k;
int main(){
    cin>>n>>k;
    if(k>=n/2) k=n/2;
    LL ans=k*(k-1)/2 + k*(k-1)/2 + k*(n-k) + k*(n-k) - k*k;
    cout<<ans<<endl;
}