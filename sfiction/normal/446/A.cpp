/*
ID: Sfiction
OJ: CF
PROB: 446A
*/
#include <cstdio>

const int MAXN=100000+10;

int n;
int num[MAXN];
int lenl[MAXN],lenr[MAXN];

int ans;

void Init(){
    int i;
    scanf("%d",&n);
    for (i=0;i<n;++i)
        scanf("%d",&num[i]);
}

void Work(){
    int i;
    int t;

    lenl[0]=1;
    for (i=1;i<n;++i)
        if (num[i]>num[i-1])
            lenl[i]=lenl[i-1]+1;
        else
            lenl[i]=1;
    lenr[n-1]=1;
    for (i=n-2;i>=0;--i)
        if (num[i]<num[i+1])
            lenr[i]=lenr[i+1]+1;
        else
            lenr[i]=1;
    ans=1;
    for (i=0;i<n;++i)
        if (ans<lenl[i])
            ans=lenl[i];
    for (i=n-2;i>0;--i)
        if (num[i-1]+1<num[i+1]){
            t=lenl[i-1]+lenr[i+1];
            if (ans<t)
                ans=t;
        }
    if (ans<n)
        ++ans;
    printf("%d",ans);
}

int main(){
    Init();
    Work();
    return 0;
}