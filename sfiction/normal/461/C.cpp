/*
ID: Sfiction
OJ: CF
PROB: 461C
*/
#include <cstdio>

const int MAXN=100000+10;

int n,q;
int num[MAXN];
int l,r,direc;

inline int lowbit(int x){
    return x&(-x);
}

void Add(int x,int inc){
    for (;x<=r;x+=lowbit(x))
        num[x]+=inc;
}

int Sum(int x){
    if (!x)
        return 0;
    int ret=0;
    for (;x;x-=lowbit(x))
        ret+=num[x];
    return ret;
}

int main(){
    int type,a,b;
    int flag,t;

    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i)
        num[i]=lowbit(i);
    l=0;
    r=n;
    direc=1;
    while (q--){
        scanf("%d%d",&type,&a);
        if (type==1){
            if (direc!=1){
                a=r-l-a;
                flag=-1;
            }
            else
                flag=1;

            if (a<=((r-l)>>1)){
                for (int i=a;i;--i){
                    t=Sum(i+l)-Sum(i+l-1);
                    Add((a<<1)-i+1+l,t);
                    Add(i+l,-t);
                }
                l=a+l;
                direc*=flag;
            }
            else{
                for (int i=r-l;i>a;--i){
                    t=Sum(i+l)-Sum(i+l-1);
                    Add((a<<1)-i+1+l,t);
                    Add(i+l,-t);
                }
                r=a+l;
                direc*=-flag;
            }
        }
        else{
            scanf("%d",&b);
            if (direc==1)
                printf("%d\n",Sum(l+b)-Sum(l+a));
            else
                printf("%d\n",Sum(r-a)-Sum(r-b));
        }
    }
    return 0;
}