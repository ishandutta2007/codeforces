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
const int N=2005,mod=1e9+7;
int n,k;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int is[N],q[N];
bool cmp(int x,int y){return is[x]<is[y];}
int ss[N];
int main(){
    scanf("%d%d",&n,&k);

    // rep(i,n)ss[i]=rand();

    // int g=gcd(n,k);
    // if(k/g%2==0){
    //     puts("-1");
    //     fflush(stdout);
    //     return 0;
    // }
    bool flag=0;
    for(int s=1;s<=n;++s){
        if(s*k-n<0||(s*k-n)%2!=0)continue;
        int mx=((s*k-n)/2/n+((s*k-n)/2%n!=0))*2+1,mi=(s*k-n)/2/n*2+1;
        if(mx>s)continue;
        int res=s*k;
        rep(i,n)is[i]=mi,res-=is[i];
        rep(i,n)if(res>0)is[i]+=2,res-=2;
        rep(i,n)q[i]=i;
        int ans=0;
        rep(tim,s){
            // rep(i,n)printf("%d ",is[i]);
            // puts("");
            sort(q+1,q+n+1,cmp);
            reverse(q+1,q+n+1);
            printf("?");
            rep(i,k)printf(" %d",q[i]);
            puts("");
            fflush(stdout);
            int X=0;scanf("%d",&X);
            // rep(i,k)X^=ss[q[i]];
            ans^=X;
            rep(i,k)--is[q[i]];
            // rep(i,n)printf("%d ",is[i]);
            // puts("");
        }
        printf("! %d\n",ans);
        fflush(stdout);

        // int X=0;
        // rep(i,n)X^=ss[i];
        // if(X!=ans)puts("FUCK");
        // rep(i,n)if(is[i]!=0)puts("FUCK");
        flag=1;
        break;
    }
    if(flag==0)puts("-1");
    return 0;
}
/*
n,m m%2=1
k*m=n+2x
x=(k*m-n)/2
k<=1+upp(x/n)
*/