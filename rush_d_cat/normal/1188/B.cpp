#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 20000 + 10;
typedef long long LL;
LL n,k,p;
map<LL,int> mp;

int main() {
    cin >> n >> p >> k;
    LL ans=0;
    for(int i=1;i<=n;i++){
        LL x; cin>>x;
        LL tmp = x*x%p*x%p*x%p - k*x%p;
        tmp=(tmp%p+p)%p;
        ans+=mp[tmp];
        mp[tmp]++;
    }
    cout<<ans<<endl;
}