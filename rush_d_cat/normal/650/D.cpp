#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 400000+10;
const int INF = 1000000007;

int bit[N];
vector<int> v;
int id(int x) {
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int get(int x) {
    int ans=0;
    while(x) {
        ans=max(ans,bit[x]);
        x-=x&-x;
    }
    return ans;
}
void upd(int pos,int x){
    while(pos<N) {
        bit[pos]=max(bit[pos],x);
        pos += pos&-pos;
    }
}
int n,m,h[N],dp[N],rdp[N],neccesary[N];
int LIS=0;
vector<int> pos[N];
void compress(int on) {
    v.clear();
    if (on == 0) {
        for(int i=1;i<=n;i++) v.push_back(h[i]);
    } else {
        for(int i=1;i<=n;i++) v.push_back(INF-h[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
void LIS_Proccess() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&h[i]);
    }
    compress(0);

    for(int i=1;i<=n;i++) {
        dp[i] = get(id(h[i])-1) + 1;
        upd(id(h[i]), dp[i]);
        LIS = max(LIS, dp[i]);
    }

    memset(bit,0,sizeof(bit));
    compress(1);
    for(int i=n;i>=1;i--) {
        rdp[i] = get(id(INF-h[i])-1) + 1;
        upd(id(INF-h[i]), rdp[i]);
    }

    for(int i=1;i<=n;i++) {
        if (dp[i]+rdp[i] == LIS+1) {
            pos[dp[i]].push_back(i);
        }
    }

    for(int i=1;i<=n;i++) {
        if (pos[i].size() == 1) {
            neccesary[pos[i][0]] = 1;
        }
    }

}

int lson[N*22],rson[N*22],val[N*22],root[N*22],pid;
int ans[N], pre[N], suf[N], p[N], x[N];
void build(int &k,int l,int r) {
    k=++pid; val[k]=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(lson[k],l,mid);
    build(rson[k],mid+1,r);
}
void change(int old,int &k,int l,int r,int pos,int x) {
    k=++pid;
    lson[k]=lson[old],rson[k]=rson[old],val[k]=max(x,val[old]);

    if(l==r) return;
    int mid=(l+r)>>1;
    if(pos<=mid) change(lson[old],lson[k],l,mid,pos,x);
    else change(rson[old],rson[k],mid+1,r,pos,x);
}
int query(int k,int l,int r,int L,int R) {
    if(L>R) return 0;
    if(L<=l&&r<=R) {

        return val[k];
    }
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans=max(ans, query(lson[k],l,mid,L,R));
    if (R >mid) ans=max(ans, query(rson[k],mid+1,r,L,R));
    return ans;
}

int main() {

    LIS_Proccess();

    // neccesary[i]: iLIS


    pid=0; compress(0);
    build(root[0],1,v.size());
    for(int i=1;i<=n;i++) {
        change(root[i-1],root[i],1,v.size(),id(h[i]),dp[i]);
    }

    for(int i=1;i<=m;i++) {
        scanf("%d%d",&p[i],&x[i]);
        ans[i] = neccesary[p[i]] ? LIS - 1 : LIS;
        pre[i] = query(root[p[i]-1], 1, v.size(), 1, id(x[i])-1);
    }
    //exit(0);

    pid=0; compress(1);
    build(root[n+1],1,v.size());
    for(int i=n;i>=1;i--) {
        change(root[i+1],root[i],1,v.size(),id(INF-h[i]),rdp[i]);
    }
    for(int i=1;i<=m;i++) {
        suf[i] = query(root[p[i]+1], 1, v.size(), 1, id(INF-x[i])-1);
        ans[i] = max(ans[i], pre[i]+suf[i]+1);
        printf("%d\n", ans[i]);
    }

}