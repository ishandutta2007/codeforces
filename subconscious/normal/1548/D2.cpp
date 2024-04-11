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
const int N=3e6+5,mod=1e9+7;
int cnt[4][4][4],a[2][N];
int n;
ll ans;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int check(int u,int v,int w,int x,int y,int z){
    int cro=(u*y-v*x%4+4)%4;
    if(cro%2!=0)return 0;
    if((u-x+4)%4==0&&(v-y+4)%4==0){
        //0
        if((w+z)%4==cro&&w%2==1&&z%2==1)return 3;
        return (w+z)%4==cro;
    }else if((u-x+4)%2==0&&(v-y+4)%2==0){
        //2
        if((w+z+2)%4==cro&&w%2==1&&z%2==1)return 3;
        return (w+z+2)%4==cro;
    }else{
        //1 or 3
        if((w+z+1)%2!=0)return 0;
        return 0;
    }
}
int main(){
    scanf("%d",&n);
    ans=0;
    rep(i,n)scanf("%d%d",&a[0][i],&a[1][i]);
    rep(i,n){
        for(int u=0;u<4;++u)
            for(int v=0;v<4;++v)
                for(int w=0;w<4;++w)
                cnt[u][v][w]=0;
        rep(j,n)if(j!=i){
            int u=((a[0][j]-a[0][i])%4+4)%4,
                v=((a[1][j]-a[1][i])%4+4)%4,
                w=gcd(abs(a[0][j]-a[0][i]),abs(a[1][j]-a[1][i]))%4;
            ++cnt[u][v][w];
        }
        for(int a0=0;a0<64;++a0){
            int ua=a0%4,va=a0/4%4,wa=a0/16%4;
            ans+=(ll)check(ua,va,wa,ua,va,wa)*cnt[ua][va][wa]*(cnt[ua][va][wa]-1)/2;
            for(int b0=a0+1;b0<64;++b0){
                int ub=b0%4,vb=b0/4%4,wb=b0/16%4;
                ans+=(ll)check(ua,va,wa,ub,vb,wb)*cnt[ua][va][wa]*cnt[ub][vb][wb];
            }
        }
    }
    ans/=3;
    printf("%lld\n",ans);
    return 0;
}
/*
 
*/