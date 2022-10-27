#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N = 700000 + 10;
namespace BIT {
    const int M = 100000 + 10;
    int Time[M],bit[M],CLOCK;
    void Rebitrh() {
        CLOCK++;
    }
    void add(int pos,int x){
        while(pos<M) {
            if(Time[pos]!=CLOCK) Time[pos]=CLOCK,bit[pos]=0;
            bit[pos]+=x; pos+=pos&-pos;
        }
    }
    int sum(int pos){
        int ans=0;
        while(pos>0) {
            if(Time[pos]!=CLOCK) Time[pos]=CLOCK,bit[pos]=0;
            ans+=bit[pos]; pos-=pos&-pos;
        } return ans;
    }
};
int n,m,a[N];
struct Nod {
    int tp,pos,val,id;
} nod[N]; LL ans[N];int tot;
bool cmp(Nod A, Nod B) {
    return A.pos < B.pos;
}
set<int> st[N]; set<int>::iterator it;
void modify(int pos,int x){
    it = st[a[pos]].find(pos); 
    int pre=0,nex=0;
    it++; if(it!=st[a[pos]].end()) nex=*it; it--;
    if(it!=st[a[pos]].begin()) it--, pre=*it, it++;
    if(nex) nod[++tot] = (Nod){-1,nex,pos,0};
    if(pre) nod[++tot] = (Nod){-1,pos,pre,0};
    if(pre&&nex) nod[++tot] = (Nod){+1,nex,pre,0};
    st[a[pos]].erase(pos);
    pre=0,nex=0; a[pos]=x; st[a[pos]].insert(pos);
    it = st[a[pos]].find(pos);
    it++; if(it!=st[a[pos]].end()) nex=*it; it--;
    if(it!=st[a[pos]].begin()) it--, pre=*it, it++;    
    if(nex) nod[++tot]=(Nod){+1,nex,pos,0};
    if(pre) nod[++tot]=(Nod){+1,pos,pre,0};
    if(nex&&pre) nod[++tot]=(Nod){-1,nex,pre,0};
}
void cdq(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    vector<Nod> vL,vR;
    for(int i=l;i<=r;i++) {
        if(i<=mid) vL.push_back(nod[i]);
        else vR.push_back(nod[i]);
    }
    sort(vL.begin(),vL.end(),cmp);
    sort(vR.begin(),vR.end(),cmp); 
    BIT::Rebitrh();
    LL All = 0;
    for(int r=0,l=0;r<vR.size();r++) {
        while(l<vL.size() && vL[l].pos<=vR[r].pos) {
            if(vL[l].tp!=2) BIT::add(vL[l].val, vL[l].tp*(vL[l].pos-vL[l].val)), All += vL[l].tp*(vL[l].pos-vL[l].val); l ++;
        }
        if(vR[r].tp==2) ans[vR[r].id] += All - BIT::sum(vR[r].val-1);
    }
    cdq(l,mid); cdq(mid+1,r);
}
int main() {
    scanf("%d%d",&n,&m); 
    bool isque[N] = {0};
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); st[a[i]].insert(i);
        it = st[a[i]].find(i);
        if (it!=st[a[i]].begin()) {
            -- it, nod[++tot] = (Nod){1,i,*it}; //printf("i=%d, pre=%d\n", i,*it);
        }
    }   
    for(int i=1;i<=m;i++) {
        int op,l,r; scanf("%d%d%d",&op,&l,&r);
        if(op==1) modify(l,r);
        if(op==2) nod[++tot]=(Nod){2,r,l,i}, isque[i]=1;
    }

    cdq(1,tot);
    for(int i=1;i<=m;i++) if(isque[i]) printf("%lld\n", ans[i]);
}