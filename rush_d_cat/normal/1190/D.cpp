#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
int n,x[N],y[N];
vector<int> vx,vy,vec[N];
int idy(int y) {
    return lower_bound(vy.begin(),vy.end(),y) - vy.begin() + 1;
}
int idx(int x) {
    return lower_bound(vx.begin(),vx.end(),x) - vx.begin() + 1;
}
LL pre[N],sum[N<<2];
void update(int l,int r,int rt,int y,int p) {
    if(l==r) {
        sum[rt] = p; return;
    }
    int mid=(l+r)>>1;
    if(y<=mid) update(l,mid,rt<<1,y,p);
    else update(mid+1,r,rt<<1|1,y,p);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
LL query(int l,int r,int rt,int L,int R){
    if(L<= l && r<=R) return sum[rt];
    int mid=(l+r)>>1;
    if(L>mid) return query(mid+1,r,rt<<1|1,L,R);
    if(R<=mid) return query(l,mid,rt<<1,L,R);
    return query(l,mid,rt<<1,L,R)+query(mid+1,r,rt<<1|1,L,R);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]); 
        vx.push_back(x[i]); vy.push_back(y[i]);
    }
    sort(vy.begin(),vy.end()); vy.erase(unique(vy.begin(),vy.end()),vy.end());
    sort(vx.begin(),vx.end()); vx.erase(unique(vx.begin(),vx.end()),vx.end());
    for(int i=1;i<=n;i++){
        vec[idy(y[i])].push_back(idx(x[i]));
    }
    LL ans=0;
    for(int i=(int)vy.size();i>=1;i--) {
        if((int)vec[i].size() == 0) continue; 
        for(auto x: vec[i]) update(1,n,1,x,1);
        LL c=query(1,n,1,1,n); ans += c*(c+1)/2;
        vec[i].push_back(0); vec[i].push_back(n+1);
        sort(vec[i].begin(),vec[i].end()); 
        for(int j=0;j+1<vec[i].size();j++) {
            if(vec[i][j]+1<=vec[i][j+1]-1) {
                LL cc = query(1,n,1,vec[i][j]+1,vec[i][j+1]-1);
                ans -= cc*(cc+1)/2;
            }
        }
    }
    cout<<ans<<endl;
}