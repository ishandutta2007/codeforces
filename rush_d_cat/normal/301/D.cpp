#include <iostream>
#include <vector>
using namespace std;
const int N = 200000 + 10;
int n,m;
int p[N],pos[N],ans[N];

vector<int> vec[N];
vector< pair<int,int> > q[N];
int bit[N];
void add(int x) {
    while(x<N) {
        bit[x]++; x += x&(-x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans += bit[x]; x -= x&(-x);
    }
    return ans;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&p[i]); pos[p[i]]=i;
    }
    for(int i=1;i<=m;i++) {
        int l,r; scanf("%d%d",&l,&r);
        q[r].push_back(make_pair(l,i));
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            vec[max(pos[j],pos[i])].push_back(min(pos[j],pos[i]));
        }
    }

    for(int i=1;i<=n;i++) {
        if(vec[i].size()) {
            for(auto x: vec[i]) {
                //printf("add %d %d\n", i, x);
                add(x);
            }
        }
        for(auto p: q[i]) {
            //printf("i=%d, p.first=%d\n", i, p.first);
            ans[p.second] = sum(N-1) - sum(p.first-1);
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n", ans[i]);
}