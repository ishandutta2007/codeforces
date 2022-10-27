#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n,q;
LL a[N];
map< pair<int,int>, int > mp;
int main() {
    scanf("%d", &n);
    LL ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i];
    }
    scanf("%d",&q);
    while(q--){
        int s,t,u;
        scanf("%d%d%d",&s,&t,&u);
        if(mp[make_pair(s,t)]) {
            a[ mp[make_pair(s,t)] ] ++;
            if (a[mp[make_pair(s,t)]] >= 1) ans ++;
        }
        mp[make_pair(s,t)] = u;
        if (u) {
            a[mp[make_pair(s,t)]] --;
            if (a[mp[make_pair(s,t)]] >= 0) ans --;
        }
        printf("%lld\n", ans);
    }
}