#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=3e6+5,mod=1e9+7;
int n,m,T,a[N],b[N];
bool in[305][305];
int to(int x,int y){return y+(x-1)*m;}
pr rev(int p){return mp((p-1)/m+1,(p-1)%m+1);}
pr q[N];
bool cmp(pr x,pr y){
    if(x.st!=y.st)return x.st<y.st;
    return x.nd>y.nd;
}
int cmp_2(int x,int y){
    if(a[x]!=a[y])
    return a[x]<a[y];
    return x<y;
}
pr pos[N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        rep(i,n*m)scanf("%d",a+i),b[i]=i;
        rep(i,n)rep(j,m)in[i][j]=0;
        sort(b+1,b+n*m+1,cmp_2);
        for(int i=1,j;i<=n*m;i=j){
            for(j=i;j<=n*m&&a[b[j]]==a[b[i]];++j);
            int top=0;
            for(int k=i;k<j;++k)
                q[++top]=rev(k);
            sort(q+1,q+top+1,cmp);
            for(int k=i;k<j;++k)
                pos[b[k]]=q[k-i+1];
        }
        int ans=0;
        rep(i,n*m){
            //printf("%d %d\n",pos[i].st,pos[i].nd);
            in[pos[i].st][pos[i].nd]=1;
            rep(j,pos[i].nd-1)ans+=in[pos[i].st][j];
        }
        printf("%d\n",ans);
    }

    return 0;
}
/*
XFOF.XFOFX
XFOFXFOF
6+10+12
9+7
*/