#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,m; LL s,t;
int mp[N],vis[N];

LL go(LL pos,LL len){
    if(pos<=m) {
        pos=(pos+len)%n;
    } else {
        pos=((pos-len)%n+n)%n;
    }
    if(pos==0)pos=n;
    return pos;
}
int getnext(int pos){
    if(mp[pos])return mp[pos];
    int now=pos;
    for(int i=n;i>=1;i--){
        now=go(now,i);
    }
    return mp[pos]=now;
}

vector<int> ans;
int main() {

    cin>>n>>m>>s>>t;

    
    while(t%n){
        s=go(s,t); t--;
    }
    LL step=t/n;
    ans.push_back(s); vis[s]=1;
    while(1) {
        s=getnext(s); if(vis[s]==1) break;
        vis[s]=1; ans.push_back(s);
    }
    int st = mp[ans[(int)ans.size() - 1]];
    for(int i=0;i<ans.size();i++){
        if(ans[i]==st) {
            int T = ans.size() - i;
            printf("%d\n", ans[i + step % T]); return 0;
        } else {
            step --; 
            if(step == 0) {
                printf("%d\n", ans[i]); return 0;
            }
        }
    }
}