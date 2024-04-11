/*
ID: Sfiction
OJ: CF
PROB: 460C
*/
#include <cstdio>
#include <cstring>

const int MAXN=100000+10;

int n,m,w;
int height[MAXN];
int rec[MAXN];

bool Check(int min){
    memset(rec,0,(n+1)*sizeof(int));
    int add=0,t,last=m;
    for (int i=0;i<n;++i){
        add+=rec[i];
        t=min-height[i]-add;
        if (t<=0)
            continue;
        if (t>last)
            return false;
        else{
            last-=t;
            if (i+w>n)
                rec[n]-=t;
            else
                rec[i+w]-=t;
            add+=t;
        }
    }
    return true;
}

int main(){
    int high,low,mid;

    scanf("%d%d%d",&n,&m,&w);
    low=1<<30;
    for (int i=0;i<n;++i){
        scanf("%d",&height[i]);
        if (low>height[i])
            low=height[i];
    }
    high=low+m+1;
    while (high-low>1){
        mid=(high+low)>>1;
        if (Check(mid))
            low=mid;
        else
            high=mid;
    }
    printf("%d",low);
    return 0;
}