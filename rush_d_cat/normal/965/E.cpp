#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)
const int N=100000+10;
const double EPS = 1e-8;
char s[N];
int n,ch[N][30],dep[N],has[N],size;
multiset<LL> st[N];
void insert(char * s) {
    int now=0;
    for(int i=0;s[i];i++) {
        int c=s[i]-'a';
        if(ch[now][c] == 0) {
            ch[now][c] = ++size;
        }
        dep[ch[now][c]]=dep[now]+1;
        now = ch[now][c];
    }
    st[now].insert(dep[now]);
    has[now]=1;
}
void dfs(int u) {
    rep(i,0,25){
        int v=ch[u][i];
        if(v==0) continue;

        dfs(v);
  
        if(st[u].size() < st[v].size()) 
            swap(st[u],st[v]);

        for(auto x:st[v]) 
            st[u].insert(x);

    }
    if (st[u].size() && has[u]==0) {
        st[u].erase(st[u].find(*st[u].rbegin()));
        st[u].insert(dep[u]);
    }

}
int main(){
    rd(n);
    rep(i,1,n){
        scanf("%s",s);
        insert(s);
    }
    has[0]=1; dfs(0); 
    LL ret=0;
    for(auto x:st[0]) {
        ret += x;
        //printf("%d\n", x);
    }
    cout<<ret<<endl;
}