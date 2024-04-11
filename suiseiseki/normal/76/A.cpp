/*#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Inf 0x7fffffffffffffff
struct Road{
    ll x,y,a,b;
    friend bool operator <(Road p,Road q){
        return p.a<q.a;
    }
}a[50005],q[205];
ll n,m;
ll A,B;
ll fa[205];
ll find(ll x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m>>A>>B;
    for(ll i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].a>>a[i].b;
    }
    sort(a+1,a+1+m);
    ll ans=Inf;
    for(ll i=1,t=0,s;i<=m;i++){
        q[++t]=a[i];
        s=0;
        for(ll j=t-1;j&&q[j+1].b<q[j].b;j--){
            swap(q[j],q[j+1]);
        }
        for(ll j=1;j<=n;j++){
            fa[j]=j;
        }
        for(ll j=1,x,y;s<n-1&&j<=t;j++){
            if((x=find(q[j].x))!=(y=find(q[j].y))){
                fa[x]=y;
                q[++s]=q[j];
            }
        }
        if(s==n-1){
            ans=min(ans,A*a[i].a+B*q[s].b);
        }
        t=s;
    }
    cout<<((ans==Inf)?-1:ans)<<endl;
    return 0;
}*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Inf 0x7fffffffffffffff
struct Road{
    int x,y,g,s;
    friend bool operator <(Road p,Road q){
        return p.g<q.g;
    }
}ed[50005];
int fa[205];
int find(int x){
    if(fa[x]==-1){
        return x;
    }
    return fa[x]=find(fa[x]);
}
bool cmp(Road p,Road q){
    return p.s<q.s;
}
bool del[50005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll gc,sc;
    cin>>gc>>sc;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&ed[i].x,&ed[i].y,&ed[i].g,&ed[i].s);
    }
    sort(ed,ed+m);
    ll ans=Inf;
    int r=0;
    int g;
    int cnt;
    int fa_x,fa_y;
    for(int i=0,j,k;i<m;i++){
        g=ed[i].g;
        ed[r++]=ed[i];
        inplace_merge(ed,ed+r-1,ed+r,cmp);
        memset(fa,-1,sizeof fa);
        cnt=0;
        for(j=0;j<r;j++){
            del[j]=0;
        }
        for(j=0;j<r;j++){
            fa_x=find(ed[j].x);
            fa_y=find(ed[j].y);
            if(fa_x!=fa_y){
                fa[fa_x]=fa_y;
                cnt++;
            }
            else{
                del[j]=1;
            }
            if(cnt==n-1){
                break;
            }
        }
        if(cnt==n-1){
            ans=min(ans,g*gc+ed[j].s*sc);
        }
        for(j=0,k=0;j<r;j++){
            if(!del[j]){
                ed[k++]=ed[j];
            }
        }
        r=k;
    }
    cout<<((ans==Inf)?-1:ans)<<endl;
    return 0;
}