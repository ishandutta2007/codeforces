#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=300000+10;
const int Mod = 1000000009;
int n,m,a[N];
struct Matrix
{
    int a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=(i==j);
    }
    Matrix operator + (const Matrix &B)const{
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                C.a[i][j]=(a[i][j]+B.a[i][j])%Mod;
        return C;
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
    void prt(){
        printf("%d %d\n%d %d\n", a[0][0],a[0][1],a[1][0],a[1][1]);
    }
} O,E,M,p[N];
int F[N],S[N];
void init(){
    E=Matrix(); E.init();
    O=Matrix();
    M=Matrix(); M.a[0][0]=M.a[0][1]=M.a[1][0]=1;
    p[0]=E; p[1]=M;
    for(int i=2;i<N;i++) p[i]=p[i-1]*M;
    F[1]=F[2]=1;S[1]=1,S[2]=2;
    for(int i=3;i<N;i++){
        F[i]=(F[i-1]+F[i-2])%Mod;
        S[i]=(S[i-1]+F[i])%Mod;
    }
}
/*
1 1
1 0
*/
struct Nod{
    int sum,l,r;
    Matrix lz;
} nod[N<<2];
void pushup(int rt){
    nod[rt].sum = (nod[rt<<1].sum + nod[rt<<1|1].sum) % Mod;
}
void build(int l,int r,int rt){
    nod[rt].l=l,nod[rt].r=r;nod[rt].lz=O;
    if(l==r){
        nod[rt].sum = a[l]; return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void upd(int rt, Matrix lz){
    int l=nod[rt].l; int r=nod[rt].r;
    //printf("l=%d,r=%d\n", l,r);
    //lz.prt();
    nod[rt].sum = (nod[rt].sum + 1LL * (S[r-l+2]-1) * lz.a[1][0] % Mod + 1LL * lz.a[1][1] * S[r-l+1] % Mod) % Mod;
    nod[rt].lz = nod[rt].lz + lz;
}
/*
1 1  s[r-l+2]-1   
1 0  s[r-l+1]     
*/
void pushdown(int rt){
    int l=nod[rt].l,r=nod[rt].r;
    int mid=(l+r)>>1;
    upd(rt<<1, nod[rt].lz);
    upd(rt<<1|1, nod[rt].lz * p[mid-l+1]);
    nod[rt].lz = O;
}
int lef,rig;
void update(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R){
        int id=l-lef;
        upd(rt, p[id]);
        return;
    }
    pushdown(rt); int mid=(l+r)>>1;
    if(L<=mid) update(l,mid,rt<<1,L,R);
    if(R >mid) update(mid+1,r,rt<<1|1,L,R);
    pushup(rt);
}
int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)
        return nod[rt].sum;
    int mid=(l+r)>>1,ans=0;
    pushdown(rt);
    if(L<=mid) ans=(ans+query(l,mid,rt<<1,L,R))%Mod;
    if(R >mid) ans=(ans+query(mid+1,r,rt<<1|1,L,R))%Mod;
    return ans;
}
/*
0 1 1 2 3 5 8
4 6 10

1 1  1
0 1  1
*/ 
int main(){
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    while(m--){
        int op;
        scanf("%d%d%d",&op,&lef,&rig);
        if(op==1) {
            update(1,n,1,lef,rig);
        } else {
            printf("%d\n", query(1,n,1,lef,rig));
        }
    }
}