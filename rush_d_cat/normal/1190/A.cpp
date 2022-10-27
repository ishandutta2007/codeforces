#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
LL n,m,k,p[N];

int main() {
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld",&p[i]);
    }
    int ans=0;
    LL dt=0;
    for(int i=1,j=1;i<=m;i=j){
        while(j<=m && (p[j]-dt-1)/k == (p[i]-dt-1)/k) j++;
        ans++; dt+=(j-i);
    }
    cout<<ans<<endl;
}