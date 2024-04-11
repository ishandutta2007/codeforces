#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
const int N=1e5+5;
struct P{
    ll x,y,z;
    P operator-(P p){return (P){x-p.x,y-p.y,z-p.z};}
    P operator*(P p){return (P){y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x};}
    ld dis(){return sqrt((ld)x*x+(ld)y*y+(ld)z*z);}
    void scan(){scanf("%lld%lld%lld",&x,&y,&z);}
}p[N];
int a[3][N],n,m,Q;
vi g[N];
struct que{
    int h,p,key;
}q[N];
ld ans[N];
bool cmp(que a,que b){return a.h>b.h;}
int seq[N];
bool cmp2(int a,int b){return p[a].z>p[b].z;}

int f[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
ld bi[3][N],tmp[4][3][N];
bool in[N];

int z[3];
int main() {
    scanf("%d",&n);
    rep(i,n)p[i].scan();
    scanf("%d",&m);
    rep(i,m){
        for(int j=0;j<3;++j)
            scanf("%d",a[j]+i),g[a[j][i]].pb(i);
        ld siz=((p[a[1][i]]-p[a[0][i]])*(p[a[2][i]]-p[a[0][i]])).dis()/2;
        //printf("%Lf\n",siz);
        for(int j=0;j<3;++j)z[j]=p[a[j][i]].z;
        sort(z,z+3);
        ld mid=siz*(z[2]-z[1])/(z[2]-z[0]);
        //[0]=0
        tmp[0][0][i]=tmp[0][1][i]=tmp[0][2][i]=0;
        //[1] z[2]=0 -> z[1]=mid
        //mid*(x-z[2])^2/(z[1]-z[2])^2
        if(z[1]==z[2]){
            tmp[1][0][i]=tmp[1][1][i]=tmp[1][2][i]=0;
        }else{
            ld ot=mid/(z[1]-z[2])/(z[1]-z[2]);
            tmp[1][0][i]=ot*z[2]*z[2];
            tmp[1][1][i]=ot*-2*z[2];
            tmp[1][2][i]=ot;
        }
        //[2] z[1]=mid <- z[0]=siz
        //siz+(mid-siz)*(x-z[0])^2/(z[1]-z[0])^2
        if(z[0]==z[1]){
            tmp[2][0][i]=tmp[2][1][i]=tmp[2][2][i]=0;
        }else{
            ld ot=(mid-siz)/(z[1]-z[0])/(z[1]-z[0]);
            tmp[2][0][i]=siz+ot*z[0]*z[0];
            tmp[2][1][i]=ot*-2*z[0];
            tmp[2][2][i]=ot;
        }
        //[3]=siz
        tmp[3][0][i]=siz;tmp[3][1][i]=tmp[3][2][i]=0;
        //for(int j=0;j<4;++j){for(int k=0;k<3;++k)printf("%Lf ",tmp[j][k][i]);puts("");}
    }
    scanf("%d",&Q);
    rep(i,Q)scanf("%d%d",&q[i].h,&q[i].p),q[i].key=i;
    sort(q+1,q+Q+1,cmp);
    rep(i,n)seq[i]=i;
    sort(seq+1,seq+n+1,cmp2);
    int ptr=1;
    rep(i,n)f[i]=i;
    rep(now,Q){
        while(ptr<=n&&p[seq[ptr]].z>q[now].h){
            int x=seq[ptr];
            in[x]=1;
            //change connect
            for(int tri:g[x]){
                for(int i=0;i<3;++i)if(in[a[i][tri]]){
                        int U=fa(x),V=fa(a[i][tri]);
                        if(U!=V){
                            f[U]=V;
                            for(int j=0;j<3;++j)
                                bi[j][V]+=bi[j][U];
                        }
                    }
            }
            //change triangle
            int fx=fa(x);
            for(int tri:g[x]){
                int cnt=in[a[0][tri]]+in[a[1][tri]]+in[a[2][tri]];
                for(int i=0;i<3;++i){
                    bi[i][fx]+=tmp[cnt][i][tri]-tmp[cnt-1][i][tri];
                }
            }
            ++ptr;
        }
        if(!in[q[now].p]){
            ans[q[now].key]=-1;
        }else{
            ld h=q[now].h;
            int fx=fa(q[now].p);
            //printf("%Lf %Lf %Lf\n",bi[0][fx],bi[1][fx],bi[2][fx]);
            ans[q[now].key]=bi[0][fx]+bi[1][fx]*h+bi[2][fx]*h*h;
        }
    }
    rep(i,Q)if(ans[i]>=-1e-9){
            printf("%.15Lf\n",ans[i]);
        }else puts("-1");
    return 0;
}
/*
5
0 0 0
2 0 0
2 2 0
0 2 0
1 1 4
4
1 2 5
2 3 5
3 4 5
4 1 5
7
0 1
0 5
1 5
2 5
3 5
4 5
5 5
 */