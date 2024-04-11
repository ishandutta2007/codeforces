#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=300000+20;
vector<int> v;
int id(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
int root[N],lson[60*N],rson[60*N],mx[60*N],tot;
int n,m,k;
void update(int old_k,int &new_k,int l,int r,int pos,int val){
    new_k=++tot;
    lson[new_k]=lson[old_k],rson[new_k]=rson[old_k];mx[new_k]=mx[old_k];
    if(l==r){
        mx[new_k]=max(val,mx[new_k]);return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(lson[old_k],lson[new_k],l,mid,pos,val);
    else update(rson[old_k],rson[new_k],mid+1,r,pos,val);
    mx[new_k]=min(mx[lson[new_k]],mx[rson[new_k]]);
}
int query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R)return mx[rt];
    int mid=(l+r)>>1,ans=1e9+7;
    if(L<=mid)ans=min(ans,query(lson[rt],l,mid,L,R));
    if(R >mid)ans=min(ans,query(rson[rt],mid+1,r,L,R));
    return ans;
} 
int l[N],r[N],p[N];
vector< pair<int,int> > vec[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&l[i],&r[i],&p[i]);
        v.push_back(r[i]); 
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=k;i++){
        vec[id(r[i])].push_back(make_pair(l[i],p[i]));
    }
    for(int i=1;i<=v.size();i++){
        bool ok=0;
        for(auto p: vec[i]){
            if(!ok)update(root[i-1],root[i],1,n,p.second,p.first),ok=1;
            else update(root[i],root[i],1,n,p.second,p.first);
        }
    }
    int cas=0;
    while(m--){
        int a,b,x,y; scanf("%d%d%d%d",&a,&b,&x,&y);
        int pos=upper_bound(v.begin(),v.end(),y) - v.begin();

        if(pos==0) printf("no\n");
        else {
            int mn = query(root[pos],1,n,a,b);
            if(mn < x) printf("no\n"); else printf("yes\n");
        }
        fflush(stdout);
    }
}