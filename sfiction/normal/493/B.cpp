/*
ID: Sfiction
OJ: CF
PROB: 493B
*/
#include <cstdio>

const int MAXN=200000+100;

int rf,f[MAXN];
int rs,s[MAXN];
long long sf,ss;

int main(){
    int n,t;
    bool ans=true;

    scanf("%d",&n);
    sf=ss=0;
    while (n--){
        scanf("%d",&t);
        ans=t>0;
        if (ans)
            sf+=f[rf++]=t;
        else
            ss+=s[rs++]=-t;
    }
    if (sf!=ss)
        ans=sf>ss;
    else{
        int i;
        for (i=0;i<rf && i<rs && f[i]==s[i];++i);
        if (i<rf && i<rs)
            ans=f[i]>s[i];
    }
    puts(ans ? "first" : "second");
    return 0;
}