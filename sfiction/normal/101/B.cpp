/*
ID: Sfiction
OJ: CF
PROB: 101B
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAXM=100000+10;
const int MOD=1000000007;
struct BIT{
    int sum[MAXM];
    int end[MAXM];
    int len;
    int all;
    inline int lowbit(int x)const{
        return x&(-x);
    }
    int find(int e){
        int low,mid,high;
        low=1;
        high=len+1;
        while (high-low){
            mid=(high+low)>>1;
            if (end[mid]<e)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
    int count(int x){
        int t=0;
        for (;x;x^=lowbit(x))
            t=(t+sum[x])%MOD;
        return t;
    }
    void add(int e,int s){
        if (e==end[len]){
            sum[len]=(sum[len]+s)%MOD;
            all=(all+s)%MOD;
        }
        else{
            ++len;
            sum[len]=(all-count(len-lowbit(len))+MOD)%MOD;
            end[len]=e;
            sum[len]=(sum[len]+s)%MOD;
            all=(all+s)%MOD;
        }
    }
    int out(int n){
        return end[len]==n?(all-count(len-1)+MOD)%MOD:0;
    }
    BIT(){
        memset(sum,0,sizeof(sum));
        memset(end,0,sizeof(end));
        sum[1]=all=1;
        len=1;
    }
};

int bus[MAXM][2];
BIT f;

int Comp(const void *a,const void *b){
    return *((int *)a+1)-*((int *)b+1);
}
int main(){
    int n,m;
    int i,u,v,s;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;++i)
        scanf("%d%d",&bus[i][0],&bus[i][1]);
    qsort(bus,m,sizeof(bus[0]),Comp);
    for (i=0;i<m;++i){
        u=f.find(bus[i][0]);
        if (f.end[f.len]==bus[i][1])
            v=f.len-1;
        else
            v=f.len;
        s=f.count(v)-f.count(u-1);
        f.add(bus[i][1],s);
    }
    printf("%d",f.out(n));
    return 0;
}