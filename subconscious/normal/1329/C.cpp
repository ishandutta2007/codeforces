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
const int N=5e6+5;
const ld eps=1e-12,inf=1e18;
int h,g,T,a[N],b[N],n,m;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&h,&g);
        n=(1<<h)-1,m=(1<<g)-1;
        rep(i,n)scanf("%d",a+i);
        for(int i=1<<h;i<2<<h;++i)
            a[i]=0;
        int top=0;
        rep(i,n)
            for(;;){
                if(a[i]==0)break;
                int cur=i;
                for(;;){
                    int L=cur<<1,R=L+1;
                    if(a[L]==0&&a[R]==0)break;
                    if(a[L]>a[R])cur=L;else cur=R;
                }
                if(cur<=m)break;
                b[++top]=i;
                cur=i;
                for(;;){
                    int L=cur<<1,R=L+1;
                    if(a[L]==0&&a[R]==0)break;
                    if(a[L]>a[R])a[cur]=a[L],cur=L;else a[cur]=a[R],cur=R;
                }
                a[cur]=0;
            }
        ll ans=0;
        rep(i,m)ans+=a[i];
        printf("%lld\n",ans);
        rep(i,n-m)printf("%d%c",b[i]," \n"[i==n-m]);
    }
    return 0;
}