#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;
vector< pair<int,int> > g[N];
int n,m;
struct Point {
    LL x,y,id;
    bool operator < (const Point & o) const {
        return (x-y) < (o.x-o.y);
    }
} nod[N];
map< pair<int,int>, int > mp;

void dfs1(int u,int p) {
    nod[u].id = u;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first;
        if(p==v) continue;
        nod[v].x = nod[u].x + g[u][i].second;
        dfs1(v,u);
    }
}
void dfs2(int u,int p) {
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first;
        if(p==v) continue;
        nod[v].y = nod[u].y + g[u][i].second;
        dfs2(v,u);
    }
}
int bit[N];
void update(int pos, int val) {
    while(pos < N) {
        bit[pos] = max(bit[pos], val), pos += pos&(-pos); 
    } 
}
int query(int pos) {
    int mx=0;
    while(pos) mx = max(mx, bit[pos]), pos -= pos&(-pos);
    return mx; 
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++) {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
        mp[make_pair(u,v)] = mp[make_pair(v,u)] = 1;
    }
    dfs1(1,0); dfs2(n,0);
    LL minDis = nod[n].x;
    sort(nod+1,nod+1+n);

    LL sum = 0;
    set< pair<LL,LL> > st;
    for(int i=1;i<=n;i++) {
        //printf("(%d,%d)\n", nod[i].x,nod[i].y);
        for(set< pair<LL,LL> >::iterator it = st.begin(); it != st.end(); it ++) {
            if (mp[make_pair(nod[i].id, it->second)] == 0) {
                sum = max(sum, nod[i].y - it->first);
                break;
            }
        }
        st.insert(make_pair(-nod[i].x, nod[i].id));
    }
    //printf("%d\n", sum);
    while(m--) {
        int x; scanf("%d", &x);
        printf("%lld\n", min(minDis, sum+x));
    }
}