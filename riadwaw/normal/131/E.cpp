#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
set<int> up[200000],lef[200000],pl[202020],mn[202020];
int r[101010],c[101010];
void solve() {
    int n,m;
    scanf(" %d %d ",&n,&m);
    for(int i=0;i<m;++i){
        int x,y;
        scanf(" %d %d ",&r[i],&c[i]);
        
        x=r[i];
        y=c[i];
        up[x].insert(y);
        lef[y].insert(x);
        pl[x+y].insert(x);
        mn[x-y+100000].insert(x);
    }
    int res[10];
    memset(res,0,sizeof(res));
    for(int i=0;i<m;++i){
        int x,y;
        
        x=r[i];
        y=c[i];
        //cout<<x<<y;
        int cur=0;
        set<int>::iterator iter = up[x].find(y);
        if(up[x].size()!=1){
            if(iter != up[x].begin())
                ++cur;
            ++iter;
            if(iter != up[x].end())
                ++cur;
        }
        if(lef[y].size()!=1){
            iter = lef[y].find(x);
            if(iter != lef[y].begin())
                ++cur;
            ++iter;
            if(iter != lef[y].end())
                ++cur;
        }
        iter = pl[x+y].find(x);
        if(iter != pl[x+y].begin())
            ++cur;
        ++iter;
        if(iter != pl[x+y].end())
            ++cur;
        iter =mn[x-y+100000].find(x);
        if(iter != mn[x-y+100000].begin())
            ++cur;
        ++iter;
        if(iter != mn[x-y+100000].end())
            ++cur;
        res[cur]++;
        //cout<<cur<<endl;
    }
    for(int i=0;i<=8;++i){
        printf("%d ",res[i]);
    }
}