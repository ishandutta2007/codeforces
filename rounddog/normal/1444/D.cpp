#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e6+100;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int> vi;
typedef bitset<maxn> bs;
bs f[1005],g[1005];
int n,_,m,a[1005],b[1005],sx,sy;
bool cmp(int u,int v){return u>v;}
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    if (n!=m){puts("No");return;}
    f[0].reset(); g[0].reset();
    f[0][0]=g[0][0]=1; sx=0; sy=0;
    for (int i=1;i<=n;i++){
        sx+=a[i]; sy+=b[i];
        f[i]=f[i-1]|(f[i-1]<<a[i]);
        g[i]=g[i-1]|(g[i-1]<<b[i]);
    }
    if (sx%2||sy%2){puts("No");return;}
    if (!f[n][sx/2]||!g[n][sy/2]){puts("No");return;}
    int now;
    now=sx/2;
    for (int i=n;i;i--){
        if (f[i-1][now]) a[i]=-a[i]; else now-=a[i];
    }
    now=sy/2;
    for (int i=n;i;i--){
        if (g[i-1][now]) b[i]=-b[i]; else now-=b[i];
    }
    vi ux,uy,dx,dy;
    ux.clear(); uy.clear();
    dx.clear(); dy.clear();
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int p=1,q=1;
    while (a[p]<0) ++p;
    while (b[q]<0) ++q;
    puts("Yes");
    if (p>q){
        sort(a+1,a+p,cmp);
        sort(a+p,a+n+1);
        sort(b+1,b+q);
        sort(b+q,b+n+1,cmp);
    } else {
        sort(a+1,a+p);
        sort(a+p,a+n+1,cmp);
        sort(b+1,b+q,cmp);
        sort(b+q,b+n+1);
    }
    int x=0,y=0;
    for (int i=1;i<=n;i++){
        printf("%d %d\n",x,y);
        if (p>q) y+=b[i]; else x+=a[i];
        printf("%d %d\n",x,y);
        if (p>q) x+=a[i]; else y+=b[i];
    }
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}