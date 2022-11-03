/*
ID: Sfiction
OJ: CF
PROB: 446C
*/
#include <cstdio>

const int MAXN=300000+10,MOD=1000000009;

struct matrix{
    long long a,b,c,d;
    void operator=(const int x){
        a=b=c=d=x;
    }
    matrix operator+(const matrix& r)const{
        matrix ret;
        ret.a=(a+r.a)%MOD;
        ret.b=(b+r.b)%MOD;
        ret.c=ret.b;
        ret.d=(d+r.d)%MOD;
        return ret;
    }

    matrix operator-(const matrix& r)const{
        matrix ret;
        ret.a=(a-r.a+MOD)%MOD;
        ret.b=(b-r.b+MOD)%MOD;
        ret.c=ret.b;
        ret.d=(d-r.d+MOD)%MOD;
        return ret;
    }

    matrix operator*(const matrix& r)const{
        matrix ret;
        ret.a=(a*r.a+b*r.b)%MOD;
        ret.b=(a*r.c+b*r.d)%MOD;
        ret.c=ret.b;
        ret.d=(c*r.c+d*r.d)%MOD;
        return ret;
    }
};

int n;
long long prefix[MAXN];
matrix mat[MAXN],matsum[MAXN];
matrix lazy[MAXN<<2],sum[MAXN<<2];

void Pre(){
    int i;
    matrix A;
    A.a=A.b=A.c=1;
    A.d=0;
    mat[0].a=0;
    mat[0].b=mat[0].c=1;
    mat[0].d=-1;
    for (i=1;i<=n;++i)
        mat[i]=mat[i-1]*A;
    matsum[1]=A;
    for (i=2;i<=n;++i)
        matsum[i]=matsum[i-1]*A+A;
}

void Fresh(int now,matrix add,int len){
    lazy[now]=lazy[now]+add;
    sum[now]=sum[now]+add*matsum[len];
}

void PushDown(int now,int len){
    Fresh(now<<1,lazy[now],len-(len>>1));
    Fresh(now<<1|1,lazy[now]*mat[len-(len>>1)+1],len>>1);
    lazy[now]=0;
}

void Update(int a,int b,int l,int r,int now){
    if (a<=l && r<=b){
        Fresh(now,mat[l-a],r-l+1);
        return;
    }
    PushDown(now,r-l+1);
    int m=(l+r)>>1;
    if (a<=m)
        Update(a,b,l,m,now<<1);
    if (m<b)
        Update(a,b,m+1,r,now<<1|1);
    sum[now]=sum[now<<1]+sum[now<<1|1];
}

matrix Query(int a,int b,int l,int r,int now){
    if (a<=l && r<=b)
        return sum[now];
    PushDown(now,r-l+1);
    int m=(l+r)>>1;
    matrix ret;
    ret=0;
    if (a<=m)
        ret=ret+Query(a,b,l,m,now<<1);
    if (m<b)
        ret=ret+Query(a,b,m+1,r,now<<1|1);
    sum[now]=sum[now<<1]+sum[now<<1|1];
    return ret;
}

int main(){
    int m;
    int com,a,b;
    int ans;
    matrix temp;

    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%I64d",&prefix[i]);
        prefix[i]=(prefix[i]+prefix[i-1])%MOD;
    }
    Pre();
    for (;m;--m){
        scanf("%d%d%d",&com,&a,&b);
        if (com==1)
            Update(a,b,1,n,1);
        else{
            ans=(prefix[b]-prefix[a-1]+MOD)%MOD;
            temp=Query(a,b,1,n,1);
            ans=(ans+temp.a)%MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}