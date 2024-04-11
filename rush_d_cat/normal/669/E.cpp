#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
int n,cnt[N],ans[N];
struct Nod {
    int tp,clock,t,x, ans;
    bool operator < (const Nod & o) const {
        return t < o.t;
    }
} nod[N]; 
bool cmp(Nod A, Nod B) {
    return A.t < B.t;
}
vector<int> v;
int id(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
void cdq(int l,int r) {
    if(l==r) return;
    
    int mid=(l+r)>>1;
    vector<Nod> vL, vR;
    for(int i=l;i<=r;i++) {
        if(i<=mid) vL.push_back(nod[i]);
        else vR.push_back(nod[i]);
    }
    sort(vL.begin(),vL.end());
    sort(vR.begin(),vR.end());
    /*
    printf("solve %d %d\n", l,r);
    printf("vL:\n");
    for(auto p:vL) {
        printf("tp=%d,clock=%d,t=%d,x=%d\n", p.tp,p.clock,p.t,p.x);
    }
    printf("vR:\n");
    for(auto p:vR) {
        printf("tp=%d,clock=%d,t=%d,x=%d\n", p.tp,p.clock,p.t,p.x);
    }
    */
    for(int l=0,r=0;r<vR.size();r++) {
        while(l<vL.size() && vL[l].t < vR[r].t) {
            if(vL[l].tp==1) cnt[vL[l].x] ++;
            if(vL[l].tp==2) cnt[vL[l].x] --;
            l ++;
        }
        if(vR[r].tp==3) {
            ans[vR[r].clock] += cnt[vR[r].x];
        }
    }


    for(int l=0,r=0;r<vR.size();r++) {
        while(l<vL.size() && vL[l].t < vR[r].t) {
            if(vL[l].tp==1) cnt[vL[l].x] --;
            if(vL[l].tp==2) cnt[vL[l].x] ++;
            l ++;
        }
    }
    cdq(l,mid); cdq(mid+1,r);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        nod[i].clock=i;
        scanf("%d%d%d",&nod[i].tp,&nod[i].t,&nod[i].x);
    }
    for(int i=1;i<=n;i++) v.push_back(nod[i].t);
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) nod[i].t = id(nod[i].t);
    v.clear();
    for(int i=1;i<=n;i++) v.push_back(nod[i].x);
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) nod[i].x = id(nod[i].x);
    cdq(1,n);
    for(int i=1;i<=n;i++) {
        if(nod[i].tp==3) printf("%d\n",ans[i]);
    }
}