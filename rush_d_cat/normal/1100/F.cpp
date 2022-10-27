#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=500000+10;
int n,q,ans[N];

struct Nod{
    int l,r,id;
    bool operator<(const Nod&o)const{
        return l<o.l;
    }
}; vector<Nod> vec;
int p[N][20],a[N];
void insert(int *p,int x){
    for(int i=19;i>=0;i--){
        if(x>>i&1)
        if(p[i]==0){
            p[i]=x; break;
        } else x ^= p[i];
    }
}
int cac(int *a,int *b){
    int c[20];for(int i=0;i<20;i++)c[i]=b[i];
    for(int i=0;i<20;i++){
        insert(b,a[i]);
    }
    int ans=0;
    for(int i=19;i>=0;i--){
        if( (ans^b[i]) > ans) ans = ans^b[i];
    } 
    for(int i=0;i<20;i++)b[i]=c[i];
    return ans;
}
void solve(int l,int r,vector< Nod > vec){
    if(l==r)return;
    int mid=(l+r)>>1;
    vector<Nod> vL,vR;
    memset(p[mid],0,sizeof p[mid]);
    memset(p[mid+1],0,sizeof p[mid+1]);

    for(int i=mid;i>=l;i--){
        if(i!=mid) for(int j=0;j<20;j++)p[i][j]=p[i+1][j];
        //printf("i=%d, v=%d\n", i,a[i]);
        insert(p[i],a[i]);
    }
    for(int i=mid+1;i<=r;i++){
        if(i!=mid+1) for(int j=0;j<20;j++)p[i][j]=p[i-1][j];
        insert(p[i],a[i]);
    }
    for(int i=0;i<vec.size();i++){
        if(vec[i].r < mid) vL.push_back(vec[i]);
        else if(vec[i].l > mid) vR.push_back(vec[i]);
        else ans[vec[i].id] = cac(p[vec[i].l],p[vec[i].r]);
    }
    solve(l,mid,vL); solve(mid+1,r,vR);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        Nod nod; scanf("%d%d",&nod.l,&nod.r); nod.id=i; vec.push_back(nod);
        if(nod.l==nod.r) ans[i]=a[nod.l];
    }
    solve(1,n,vec);
    for(int i=1;i<=q;i++)
        printf("%d\n", ans[i]);
}