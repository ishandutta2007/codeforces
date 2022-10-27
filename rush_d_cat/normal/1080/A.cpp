#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n,k;
int main() {
    cin>>n>>k;
    LL ans=(2*n+k-1)/k + (5*n+k-1)/k + (8*n+k-1)/k;
    cout<<ans<<endl;
}