#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
typedef long double ld;
const int N=3e6+5,mod=1e9+7;
const ld eps=1e-12,inf=1e18;
int a[N],n,m,s[N];
int main(){
    scanf("%d%d",&n,&m);
    rep(i,m)scanf("%d",a+i);
    s[m]=n-a[m]+1;
    for(int i=m-1;i;--i){
        int L=max(i,s[i+1]-a[i]),R=min(s[i+1]-1,n-a[i]+1);
        if(L>R){puts("-1");return 0;}
        s[i]=L;
    }
    if(s[1]!=1){puts("-1");return 0;}
    rep(i,m)printf("%d%c",s[i]," \n"[i==m]);
    return 0;
}