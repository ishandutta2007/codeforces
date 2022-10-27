#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
map<LL, set<LL> > mp;
const int N = 150000+10;
LL n, a[N]; bool vis[N];

int main() {
    scanf("%lld", &n);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
        mp[a[i]].insert(i);
    }
    vector<LL> ret; int ans=0; 
    for(map<LL, set<LL> >::iterator it = mp.begin(); it!=mp.end(); it++) {
        set<LL> tmp = (*it).second;

        while (true) {
            if (tmp.size()==1) { 
                vis[*tmp.begin()]=1;
                a[*tmp.begin()] = (*it).first;
                ans++; break; 
            }
            if (tmp.size()==0) break;
            int fi = *tmp.begin(); tmp.erase(fi);
            int se = *tmp.begin(); tmp.erase(se);
            //printf("%d %d\n", fi, se);
            mp[2L*((*it).first)].insert(se);
            //printf("! %d %d\n", 2L*((*it).first), se);
        }
    }
    printf("%d\n", ans);
    for(int i=0;i<N;i++)if(vis[i])printf("%lld ", a[i]);
}