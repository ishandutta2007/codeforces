#include <iostream>
#include <map>
using namespace std;

typedef long long LL;
const int N=200000+10;
map<LL,int> mp;
int n;
LL ans[N];

int main() {
    scanf("%d",&n);
    LL pos = 1e18;
    for(int i=1;i<=n;i++) {
        LL l,r; 
        scanf("%lld %lld",&l,&r);
        mp[l] ++; mp[r+1] --;
        pos = min(pos, l);
    }
    int cnt=0;
    for(map<LL,int>::iterator it=mp.begin();it!=mp.end();it++) {
        LL cur=it->first;
        //printf("cnt=%d, [%lld,%lld)\n", cnt,pos,cur);
        ans[cnt] += cur-pos, pos=cur;
        cnt+=it->second;
    }
    for(int i=1;i<=n;i++){
        printf("%lld ", ans[i]);
    }
}