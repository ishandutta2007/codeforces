#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N=200000+10;
int n,q;
int mn[N<<2];
vector<int> vx,vy;
int x[N],y[N],d[N];
int idx(int val){
    return lower_bound(vx.begin(),vx.end(),val) - vx.begin();
}
int idy(int val){
    return lower_bound(vy.begin(),vy.end(),val) - vy.begin();
}
int mx[2][N<<2],lz[2][N<<2];

void pushdown(int id,int rt){
    if(lz[id][rt]){
        mx[id][rt<<1] = max(mx[id][rt<<1], lz[id][rt]);
        lz[id][rt<<1] = max(lz[id][rt<<1], lz[id][rt]);
        mx[id][rt<<1|1] = max(mx[id][rt<<1|1], lz[id][rt]);
        lz[id][rt<<1|1] = max(lz[id][rt<<1|1], lz[id][rt]);    
        lz[id][rt] = 0;
    }
}
void update(int id,int l,int r,int rt,int L,int R,int val){
    if(L<=l&&r<=R){
        mx[id][rt]=max(mx[id][rt],val);
        lz[id][rt]=max(lz[id][rt],val);
        return;
    }
    int mid=(l+r)>>1; pushdown(id,rt);
    if(L<=mid) update(id,l,mid,rt<<1,L,R,val);
    if(R >mid) update(id,mid+1,r,rt<<1|1,L,R,val);
    mx[id][rt]=max(mx[id][rt<<1],mx[id][rt<<1|1]);
}
int query(int id,int l,int r,int rt,int pos){
    if(l==r) return mx[id][rt];
    int mid=(l+r)>>1; pushdown(id,rt);
    if(pos<=mid) return query(id,l,mid,rt<<1,pos);
    return query(id,mid+1,r,rt<<1|1,pos);
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x[i],&y[i]);
        char s[2];scanf("%s",s);
        if(s[0]=='U')d[i]=1;
        vx.push_back(x[i]); vy.push_back(y[i]);
    }
    vx.push_back(0); vy.push_back(0);
    sort(vx.begin(),vx.end()); sort(vy.begin(),vy.end());
    vx.erase(unique(vx.begin(),vx.end()), vx.end());
    vy.erase(unique(vy.begin(),vy.end()), vy.end());
    set<int> st;
    for(int i=1;i<=q;i++){
        if(st.count(x[i])) {
            printf("0\n");
            continue;
        }
        st.insert(x[i]);
        if(d[i]==1){
            int pos=query(0,1,vx.size(),1, idx(x[i]));
            printf("%d\n", y[i]-vy[pos]);
            update(1,1,vy.size(),1, pos+1, idy(y[i]), idx(x[i]));
        } else {
            int pos=query(1,1,vy.size(),1, idy(y[i]));
            printf("%d\n", x[i]-vx[pos]);
            update(0,1,vx.size(),1, pos+1, idx(x[i]), idy(y[i]));
        }
    }
}