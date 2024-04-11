#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=(1<<19)+5,inf=1e9+7;
int n,k,in[N];
int mi[N],ma[N],ans[N];
int main(){
    scanf("%d%d",&n,&k);
    rep(i,n){
        int x;scanf("%d",&x);
        ++in[x];
    }
    for(int mk=0;mk<1<<k;++mk){
        if(in[mk])mi[mk]=ma[mk]=mk;
        else mi[mk]=inf,ma[mk]=-inf;
        ans[mk]=inf;
    }
    for(int i=0;i<k;++i){
        for(int fs=0;fs<1<<k;fs+=1<<(i+1)){
            int nd=fs+(1<<i);
            for(int mk=0;mk<1<<i;++mk){
                int mi0=mi[fs|mk],mi1=mi[nd|mk];
                int ma0=ma[fs|mk],ma1=ma[nd|mk];
                int ans0=ans[fs|mk],ans1=ans[nd|mk];
                // printf("%d %d %d:\n",fs,nd,mk);
                // printf("%d %d\n",mi0,mi1);
                // printf("%d %d\n",ma0,ma1);
                // printf("%d %d\n",ans0,ans1);
                mi[fs|mk]=min(mi0,mi1);
                mi[nd|mk]=min(mi0^(1<<i),mi1^(1<<i));
                ma[fs|mk]=max(ma0,ma1);
                ma[nd|mk]=max(ma0^(1<<i),ma1^(1<<i));
                ans[fs|mk]=min(mi1-ma0,min(ans0,ans1));
                //printf("fs:%d %d %d %d\n",fs,nd,mk,ans[fs|mk]);
                int tmp=(mi0^(1<<i))-(ma1^(1<<i));
                ans[nd|mk]=min(ans0,ans1);
                if(tmp>0)ans[nd|mk]=min(tmp,ans[nd|mk]);
                //printf("nd:%d %d %d %d\n",fs,nd,mk,ans[nd|mk]);
            }
        }
    }
    for(int mk=0;mk<1<<k;++mk)
        printf("%d%c",ans[mk]," \n"[(mk+1)==(1<<k)]);
    return 0;
}