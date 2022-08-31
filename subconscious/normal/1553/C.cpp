#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=2e6+5,mod=1e9+7;
int T,n,m,ans;
char s[N],t[N];
void dfs(int now){
    if(now==11){
        int res0=5,res1=5,abg=0;
        rep(i,10){
            if(i&1)--res1;else --res0;
            if(t[i]=='1'){
                if(i&1)++abg;else --abg;
            }
            if(abg+res1<0||abg-res0>0){
                ans=min(ans,i);
                return;
            }
        }
        ans=min(ans,10);
        return;
    }
    if(s[now]!='0'){
        t[now]='1';
        dfs(now+1);
    }
    if(s[now]!='1'){
        t[now]='0';
        dfs(now+1);
    }
}
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%s",s+1);
        ans=10;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}