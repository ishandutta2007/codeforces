#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 400000+10;
int n,m,q;
vector<int> v[N];
int par[N];
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
int main() {
    for(int i=0;i<N;i++) par[i]=i;
    scanf("%d%d%d",&n,&m,&q); 
    while(q--) {
        int x,y; scanf("%d%d",&x,&y); y+=n;
        par[find(x)] = find(y);
    }
    set<int> ans;
    for(int i=1;i<=n+m;i++) {
        ans.insert(find(i));
        //printf("%d %d\n", i, find(i));
    }
    printf("%d\n", (int)ans.size()-1);
}