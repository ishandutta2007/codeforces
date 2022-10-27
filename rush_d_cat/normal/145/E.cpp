#include <iostream>
#include <cstring>
using namespace std;
const int N=1000000+10;
int n,m; char s[N];
struct Nod{
    int mx[2][2],lz;
    Nod(){}
    Nod(char c){
        memset(mx,0,sizeof(mx));
        if(c=='4') mx[0][0]=1;
        if(c=='7') mx[1][1]=1;
        lz=1;
    }
    Nod operator+(const Nod&o)const{
        Nod ans;
        ans.mx[0][0]=mx[0][0]+o.mx[0][0];
        ans.mx[0][1]=max(mx[0][1]+o.mx[1][1], mx[0][0]+o.mx[0][1]); ans.mx[0][1]=max(ans.mx[0][1], mx[0][0]+o.mx[1][1]);
        ans.mx[1][0]=max(mx[1][0]+o.mx[0][0], mx[1][1]+o.mx[1][0]); ans.mx[1][0]=max(ans.mx[1][0], mx[1][1]+o.mx[0][0]);
        ans.mx[1][1]=mx[1][1]+o.mx[1][1];
        ans.lz=1;
        return ans;
    }
} nod[N<<2];
void neg(Nod &tmp) {
    tmp.lz *= -1;
    swap(tmp.mx[0][0],tmp.mx[1][1]); swap(tmp.mx[0][1],tmp.mx[1][0]);
}
void build(int l,int r,int rt) {
    if(l==r){
        nod[rt]=Nod(s[l]); return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
void pushdown(int rt){
    if(nod[rt].lz!=1){
        nod[rt].lz=1; neg(nod[rt<<1]), neg(nod[rt<<1|1]);
    }
}
void update(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) {
        neg(nod[rt]); return;
    }
    int mid=(l+r)>>1; pushdown(rt);
    if(L<=mid) update(l,mid,rt<<1,L,R);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}

int main(){
    scanf("%d%d%s",&n,&m,s+1);
    build(1,n,1);
    while(m--){
        char op[5]; scanf("%s",op);
        if(op[0]=='c') {
            int ans=0;
            for(int i=0;i<2;i++){
                for(int j=i;j<2;j++)ans=max(ans,nod[1].mx[i][j]);
            }
            printf("%d\n", ans);
        }
        if(op[0]=='s') {
            int l,r; scanf("%d%d",&l,&r);
            update(1,n,1,l,r);
        }
    }

}