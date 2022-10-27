#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int N=200000+10;

int n,m,q;
map<string,int> mp;
int p[N],w[N];
int find(int x){
    if(p[x]==-1) return x;
    int par=find(p[x]);
    w[x] ^= w[p[x]];
    return p[x]=par;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) p[i]=-1;
    for(int i=1;i<=n;i++) {
        string s; cin>>s;
        mp[s]=i;
    }
    for(int i=1;i<=m;i++) {
        int op; string s1, s2;
        cin>>op>>s1>>s2;
        int x=mp[s1];
        int y=mp[s2];
        int px = find(x);
        int py = find(y);
        if (px != py) {
            p[px]=py;
            if(op==1) {
                w[px]=(w[x]==w[y]?0:1);
            }
            if(op==2) {
                w[px]=(w[x]==w[y]?1:0);
            }
            printf("YES\n");
        } else {
            if(op==1&&w[x]!=w[y]) printf("NO\n");
            else if(op==2&&w[x]==w[y]) printf("NO\n");
            else printf("YES\n");
        }
    }
    for(int i=1;i<=q;i++) {
        string s1,s2;cin>>s1>>s2;
        int px=find(mp[s1]);
        int py=find(mp[s2]);
        if (px!=py) printf("3\n");
        else printf("%d\n", w[mp[s1]]==w[mp[s2]]?1:2);
    }
}