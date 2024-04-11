/*
ID: Sfiction
OJ: CF
PROB: 446B
*/
#include <cstdio>

const int MAXN=1000+5,MAXK=1000000+5;

struct heap{
    long long a[MAXN];
    int len;

    void down(int i){
        int l,r;
        int max;
        long long t;
        while (i<len){
            l=i<<1;
            r=l+1;
            if (l<=len&&a[l]>a[i])
                max=l;
            else
                max=i;
            if (r<=len&&a[r]>a[max])
                max=r;
            if (max==i)
                break;
            else{
                t=a[i];
                a[i]=a[max];
                a[max]=t;
                i=max;
            }
        }
    }

    void build(){
        int i;
        for (i=len>>1;i;--i)
            down(i);
    }
};

int n,m;
int k;
long long p;
long long rowval[MAXK];
long long colval[MAXK];

heap row,col;

void Init(){
    int i,j;
    int t;
    scanf("%d%d",&n,&m);
    scanf("%d%I64d",&k,&p);

    row.len=n;
    for (i=1;i<=n;++i)
        row.a[i]=0;
    col.len=m;
    for (i=1;i<=m;++i)
        col.a[i]=0;
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j){
            scanf("%d",&t);
            row.a[i]+=t;
            col.a[j]+=t;
        }
    row.build();
    col.build();
}

void Work(){
    long long ans;
    long long det,t;
    int i;
    det=p*m;
    rowval[0]=0;
    for (i=1;i<=k;++i){
        rowval[i]=rowval[i-1]+row.a[1];
        row.a[1]-=det;
        row.down(1);
    }
    det=p*n;
    colval[0]=0;
    for (i=1;i<=k;++i){
        colval[i]=colval[i-1]+col.a[1];
        col.a[1]-=det;
        col.down(1);
    }
    for (i=0;i<=k;++i){
        t=i*p*(k-i);
        t=rowval[i]+colval[k-i]-t;
        if (i==0||ans<t)
            ans=t;
    }
    printf("%I64d",ans);
}

int main(){
    Init();
    Work();
    return 0;
}