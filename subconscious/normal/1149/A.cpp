#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second
#define x0 fxxk
#define y0 fxck
#define x1 fuxk
#define y1 fucx
using namespace std;
using ll=long long;
using ld=long double;
using pr=pair<int,int>;
constexpr int N=2e5+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
int a[N],n;
int cnt[5],ans[N],top;
bool is[N];
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i),++cnt[a[i]];
    if(cnt[2]>0){
        ans[++top]=2,--cnt[2];
        if(cnt[1]>0){
            ans[++top]=1,--cnt[1];
        }
    }
    rep(i,cnt[2])ans[++top]=2;
    rep(i,cnt[1])ans[++top]=1;
    rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}