#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=300000+10;
int n,q;
int l[N],r[N],k[N];
vector<int> vec; 
int id(int x){
    return lower_bound(vec.begin(),vec.end(),x) - vec.begin() + 1;
}
int sum[N<<3],lz[N<<3];
void pushdown(int rt,int l,int r){
    int mid=(l+r)>>1;
    if(lz[rt]!=-1){
        lz[rt<<1]=lz[rt]; sum[rt<<1]=(vec[mid-1]-vec[l-1])*lz[rt];
        lz[rt<<1|1]=lz[rt]; sum[rt<<1|1]=(vec[r-1]-vec[mid-1])*lz[rt];
        lz[rt]=-1;
    }
}
void update(int l,int r,int rt,int L,int R,int x){
    //printf("l=%d,r=%d,rt=%d,L=%d,R=%d\n", l,r,rt,L,R);

    if(L<=l&&r<=R){
        sum[rt]=(x?(vec[r-1]-vec[l-1]):0); lz[rt]=x;
        return;
    }
    int mid=(l+r)>>1; pushdown(rt,l,r);
    if(L<mid) update(l,mid,rt<<1,L,R,x);
    if(R>mid) update(mid,r,rt<<1|1,L,R,x);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&l[i],&r[i],&k[i]);
        vec.push_back(l[i]); r[i]++;
        vec.push_back(r[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(int i=1;i<N<<3;i++) lz[i]=-1;
    for(int i=1;i<=q;i++){
        if(k[i]==2)k[i]=0;
        update(1,vec.size(),1, id(l[i]),id(r[i]),k[i]);
        printf("%d\n", n-sum[1]);
        //return 0;
    }
}