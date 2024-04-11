#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckjsb
#define y1 fuckjtjl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1005,inf=0x3f3f3f3f,MOD=1e9+7;
int l[N],r[N],ans[N],n;
int t[N];
void ins(int p){for(;p<N;p+=p&-p)++t[p];}
int que(int p){int s=0;for(;p;p-=p&-p)s+=t[p];return s;}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",l+i);
    rep(i,n)scanf("%d",r+i);
    vector<int>s;
    for(int i=n;i;--i){
        s.clear();
        rep(j,n)if(ans[j]==0&&que(j-1)==l[j]&&que(n)-que(j)==r[j])
            s.push_back(j);
        for(auto p:s)ans[p]=i,ins(p);
    }
    rep(i,n)if(ans[i]==0){puts("NO");return 0;}
    puts("YES");
    rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}