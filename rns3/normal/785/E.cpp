#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)

typedef long long LL;

const int N=210000;

int cl[N*100],cr[N*100],sum[N*100],tot;
int root[N];
int a[N], n, q;
void segadd(int &me, int l, int r, int x, int v){
    if(!me)me=++tot;
    sum[me]+=v;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)segadd(cl[me],l,mid,x,v);
    else segadd(cr[me],mid+1,r,x,v);
}

int segask(int me,int l,int r,int x,int y){
    if(!me)return 0;
    if(x<=l&&r<=y)return sum[me];
    int ans=0;
    int mid=(l+r)>>1;
    if(x<=mid)ans+=segask(cl[me],l,mid,x,y);
    if(y>mid)ans+=segask(cr[me],mid+1,r,x,y);
    return ans;
}

void add(int x,int w,int v){
    for(;x<=n;x+=(x&(-x)))segadd(root[x],1,n,w,v);
}

int preask(int x,int vl,int vr){
    int ans=0;
    if(vl<=x)ans+=min(vr-vl+1,x-vl+1);
    for(;x;x-=(x&(-x)))ans+=segask(root[x],1,n,vl,vr);
    return ans;
}

int ask(int l,int r,int vl,int vr){
    if(l>r)return 0;
    if(vl>vr)return 0;
    return preask(r,vl,vr)-preask(l-1,vl,vr);
}

int main(){
    scanf("%d %d",&n,&q);
    rep(i,1,n)a[i]=i;
    LL ans = 0;
    while(q --){
        int x,y;scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        add(x,a[x],-1);
        add(y,a[y],-1);
        ans -= ask(x + 1, y - 1, 1, a[x] - 1);
        ans -= ask(x + 1, y - 1, a[y] + 1, n);
        swap(a[x],a[y]);
        add(x,a[x],1);
        add(y,a[y],1);
        ans += ask(x + 1, y - 1, 1, a[x] - 1);
        ans += ask(x + 1, y - 1, a[y] + 1, n);
        if(a[x] > a[y])ans ++;
        else if(a[x] < a[y])ans --;
        printf("%I64d\n",ans);
    }
    return 0;
}