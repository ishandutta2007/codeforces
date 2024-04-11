#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 500000 + 10;
typedef long long LL;
namespace BIT {
    const int M = 10000 + 100;
    int Time[N],bit[N],CLOCK;
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
        }
        return ans;
    }
};
int n,k;
struct Nod{
    int tp,x,f,id;
} nod[N]; int tot,ans[N];
bool cmp(Nod A, Nod B) {
    if(A.x==B.x) return A.tp < B.tp;
    return A.x < B.x;
}
struct Item{
    int x,r,f;
    bool operator < (const Item & o) const {
        return r > o.r;
    }
    void read() {
        scanf("%d%d%d",&x,&r,&f);
    }
} it[N];
Nod vL[N],vR[N]; int szL=0,szR=0;
void cdq(int l,int r) {
    if(r-l==0) return;
    int mid=(l+r)>>1;
    szL = szR = 0;
    for(int i=l;i<=r;i++) {
        if(i<=mid) vL[szL++]=nod[i]; else vR[szR++]=nod[i];
    }
    sort(vL,vL+szL,cmp);
    sort(vR,vR+szR,cmp);
    BIT::Rebitrh();
    for(int r=0,l=0;r<szR;r++) {
        while(l<szL && vL[l].x <= vR[r].x) {
            if(vL[l].tp==2) BIT::add(vL[l].f, 1); 
            l++;
        }
        if(vR[r].tp==-1) ans[vR[r].id] -= BIT::sum(vR[r].f);
        if(vR[r].tp==+1) ans[vR[r].id] += BIT::sum(vR[r].f);
    }  
    cdq(l,mid); cdq(mid+1,r);
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        it[i].read(); it[i].f += 20;
    }
    sort(it+1,it+1+n);
    for(int i=1;i<=n;i++) {
        nod[++tot] = (Nod){+1,it[i].x-it[i].r-1,it[i].f-k-1, i};
        nod[++tot] = (Nod){-1,it[i].x-it[i].r-1,it[i].f+k, i};
        nod[++tot] = (Nod){-1,it[i].x+it[i].r,it[i].f-k-1, i};
        nod[++tot] = (Nod){+1,it[i].x+it[i].r,it[i].f+k, i};
        nod[++tot] = (Nod){2,it[i].x,it[i].f, i};
        //printf("ins %d %d\n", it[i].x, it[i].f);
        //printf("que +1 %d %d\n",it[i].x-it[i].r-1,it[i].f-k-1);
        //printf("que +1 %d %d\n",it[i].x+it[i].r,it[i].f+k);
        //printf("que -1 %d %d\n",it[i].x-it[i].r-1,it[i].f+k);
        //printf("que -1 %d %d\n",it[i].x+it[i].r,it[i].f-k-1);
    }
    cdq(1,tot);
    LL ret=0; for(int i=1;i<=n;i++) ret+=ans[i]; cout<<ret<<endl;
}