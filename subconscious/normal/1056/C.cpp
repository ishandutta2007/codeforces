#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckyzx
#define y0 fuckyxc
#define x1 fuckxzc
#define y1 fucxyzc
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-12;
int to[N],p[N],n,m,q[N],bg[N];
bool d[N];
bool cmp(int x,int y){
    if(to[x]!=to[y])return to[x]<to[y];
    return p[x]>p[y];
}
bool flag;
void do1(){
    if(flag==1){flag=0;return;}
    rep(i,m)if(d[bg[i]]==0){
        printf("%d\n",bg[i]);
        d[bg[i]]=1;
        fflush(stdout);
        return;
    }
    rep(i,n<<1)if(d[q[i]]==0){
        printf("%d\n",q[i]);
        d[q[i]]=1;
        fflush(stdout);
        return;
    }
}
void do2(){
    int x;scanf("%d",&x);d[x]=1;
    if(to[x]!=0&&d[to[x]]==0){
        printf("%d\n",to[x]);
        d[to[x]]=1;
        fflush(stdout);
        flag=1;
        return;
    }
}
int main(){
    flag=0;
    scanf("%d%d",&n,&m);
    rep(i,n<<1)scanf("%d",p+i);
    rep(i,m){
        int x,y;scanf("%d%d",&x,&y);
        if(p[x]<p[y])swap(x,y);
        bg[i]=x;
        to[x]=y,to[y]=x;
    }
    rep(i,n<<1)q[i]=i;
    sort(q+1,q+n*2+1,cmp);
    int t;
    scanf("%d",&t);
    rep(i,n){
        if(t==1)do1(),do2();
        else do2(),do1();
    }
    return 0;
}