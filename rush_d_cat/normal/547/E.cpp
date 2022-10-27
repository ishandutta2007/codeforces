#include <iostream>
#include <cstring>
using namespace std;
const int N = 400000 + 10;
typedef long long LL;
char s[N];int n;
int height[N],rk[N],sa[N],cc[N],t1[N],t2[N],id[N],pos[N],len[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k>=n?-1:y[a+k];
    int b1=y[b],b2=b+k>=n?-1:y[b+k];
    return a1==b1&&a2==b2;
}
void buildSA(int m) {
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++) cc[i]=0;
    for(int i=0;i<n;i++) cc[x[i]=s[i]]++;
    for(int i=1;i<m;i++) cc[i]+=cc[i-1];
    for(int i=n-1;i>=0;i--) sa[--cc[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++)
            if(sa[i]>=k) y[p++]=sa[i]-k;

        for(int i=0;i<m;i++) cc[i]=0;
        for(int i=0;i<n;i++) cc[x[y[i]]] ++;
        for(int i=1;i<m;i++) cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--) sa[--cc[x[y[i]]]]=y[i];
        swap(x,y);
        m=1,x[sa[0]]=0;
        for(int i=1;i<n;i++) {
            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?m-1:m++;
        }
        if(m>=n) break;
    }
}
void buildH(){
    for(int i=0;i<n;i++)
        rk[sa[i]]=i;
    int k=0; height[0]=0;
    for(int i=0;i<n;i++) {
        if(!rk[i]) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

int LG[N],st[N][20];
void RmqInit() {
    for(int i=1;i<N;i++) {
        int t = i, c = 0;
        while(t>1) { t/=2; c ++; }
        LG[i] = c;
    }
    for(int i=0;i<n;i++)
        st[i][0]=height[i];

    for(int i=1;i<20;i++)
    for(int j=0;j<n;j++)
        if(j+(1<<i)<=n)
            st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
}

int LCP(int x, int y) { // suffix(x) & suffix(y)
    if (x==y) return n-x;
    int l = min(x, y) + 1;
    int r = max(x, y); 
    int k = LG[r-l+1];
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

int lson[N*30],rson[N*30],sum[N*30],root[N],tot;
void update(int old_k,int &new_k,int l,int r,int pos){
    new_k=++tot;
    lson[new_k]=lson[old_k],rson[new_k]=rson[old_k],sum[new_k]=sum[old_k]+1;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)update(lson[old_k],lson[new_k],l,mid,pos);
    else update(rson[old_k],rson[new_k],mid+1,r,pos);
}
int query(int old_k,int new_k,int l,int r,int x){
    if(x>r||x<l)return 0;
    if(l==r)return sum[new_k]-sum[old_k];
    int mid=(l+r)>>1;
    if(x<=mid)return query(lson[old_k],lson[new_k],l,mid,x);
    return sum[lson[new_k]]-sum[lson[old_k]]+query(rson[old_k],rson[new_k],mid+1,r,x);
}

int strcnt,q;
void init() {
    scanf("%d%d",&strcnt,&q);
    char tmp[N];
    for(int i=1;i<=strcnt;i++){
        scanf("%s",tmp); len[i]=strlen(tmp);
        pos[i]=n;
        for(int j=0;tmp[j];j++)id[n]=i,s[n++]=tmp[j];
        s[n++]='a'-1;
    }
    buildSA(1000); buildH(); 

    RmqInit();

    //printf("%s\n", s);
    for(int i=1;i<=n;i++){
        //printf("i=%d, id=%d\n", i,id[sa[i-1]]);
        if(id[sa[i-1]])
        update(root[i-1],root[i],1,strcnt,id[sa[i-1]]);
    }
}

pair<int,int> get(int x,int low){
    int lef,rig;
    int l=-1,r=x;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(LCP(mid,x)>=low) r=mid; else l=mid;
    }
    lef=r;

    l=x,r=n;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(LCP(mid,x)>=low) l=mid; else r=mid;
    }
    rig=l;
    return make_pair(lef,rig);
}

int main() {
    init();
    while(q--){
        int l,r,k; scanf("%d%d%d",&l,&r,&k);
        int x = rk[pos[k]];
        pair<int,int> bu = get(rk[pos[k]], len[k]);
        int lef = bu.first+1, rig = bu.second+1;
        //printf("x:%d lef:%d rig:%d\n", x,lef,rig);       
        LL ans = query(root[lef-1],root[rig],1,strcnt,r) - query(root[lef-1],root[rig],1,strcnt,l-1);
        printf("%lld\n", ans);
    }
}