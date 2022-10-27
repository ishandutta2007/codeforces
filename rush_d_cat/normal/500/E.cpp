#include <iostream>
#include <algorithm>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n,q,len[N];
int nex[N][20]; LL cost[N][20],p[N];
pair<int,int> mx[N<<2];
pair<int,int> max(pair<int,int> A,pair<int,int> B){
    if(A.first==B.first)return B.second<A.second?B:A;
    return A.first<B.first?B:A;
}
void update(int l,int r,int rt,int pos,int x,int y){
    if(l==r) {mx[rt]=make_pair(x,y);return;}
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,rt<<1,pos,x,y);
    else update(mid+1,r,rt<<1|1,pos,x,y);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
pair<int,int> query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return mx[rt];
    int mid=(l+r)>>1; pair<int,int> ans=make_pair(0,0);
    if(L<=mid)ans=max(ans,query(l,mid,rt<<1,L,R));
    if(R >mid)ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld%d",&p[i],&len[i]); p[n+1]=2e9+7;
    for(int i=n;i>=1;i--){
        int l=i+1,r=upper_bound(p+1,p+1+n,p[i]+len[i])-p-1;
        pair<int,int> ret = make_pair(r+1,p[r+1]-(p[i]+len[i]));
        if(i<l&&l<=r&&r<=n) ret = max(ret,query(1,n,1,l,r));
        update(1,n,1,i,ret.first,ret.second);
        nex[i][0]=ret.first, cost[i][0]=ret.second;
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            nex[i][j]=nex[nex[i][j-1]][j-1];
            cost[i][j]=cost[i][j-1] + cost[nex[i][j-1]][j-1];
        } 
    }
    int q; scanf("%d",&q); while(q--) {
        int l,r; scanf("%d%d",&l,&r);
        LL sum=0;
        for(int i=19;i>=0;i--) {
            if(nex[l][i] <= r && nex[l][i]) {
                sum += cost[l][i]; l = nex[l][i];
            }
        } 
        printf("%lld\n", sum);
    }
}