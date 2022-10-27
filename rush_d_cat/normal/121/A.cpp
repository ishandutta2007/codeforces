#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> v;
void dfs(int dep,LL now) {
    v.push_back(now);
    if(dep==9) return;
    dfs(dep+1, now*10+4);
    dfs(dep+1, now*10+7);
}
int main() {
    dfs(0,0); v.push_back(4444444444LL);
    sort(v.begin(),v.end());
    LL l,r; cin>>l>>r;
    LL ans = 0;
    for(int i=0;i<v.size()-1;i++) {
        LL L=v[i]+1, R=v[i+1];
        LL val = v[i+1];
        ans = ans + val * max(min(R,r)-max(L,l)+1,0LL);
    }
    cout<<ans<<endl;
}