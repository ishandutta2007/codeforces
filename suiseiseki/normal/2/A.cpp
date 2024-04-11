#include<cstdio>
#include<cstring>
using namespace std;
const int Inf=0x7FFFFFFF;
struct Map {
    int sum;
    int t;
    char *p_s;
}M[1002];        //
struct Data {
    char str[35];
    int score;
    Map *p_M;
}D[1002];
bool Check(const char *a,const char *b) {    //strcmp
    if(strlen(a)!=strlen(b))
        return 0;
    for(int i=0;a[i];++i)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
int main() {
    int n,m=0,Max=-Inf,p=0;        //Max
    scanf("%d",&n);
    for(int i=1,j;i<=n;++i) {
        scanf("%s%d",D[i].str,&D[i].score);
        for(j=1;j<=m;++j)
            if(Check(M[j].p_s,D[i].str))    //
                break;
        D[i].p_M=&M[j];            //
        M[j].p_s=D[i].str;        //
        M[j].sum+=D[i].score;    //
        if(j>m)        //j>m
            ++m;    //
    }
    for(int i=1;i<=m;++i)
        if(M[i].sum>Max)
            Max=M[i].sum;    //
    for(int i=1;i<=n&&!p;++i) {
        D[i].p_M->t+=D[i].score;
        if(D[i].p_M->sum==Max&&D[i].p_M->t>=Max)    //
            p=i;    //ii!p
    }
    printf("%s",D[p].str);
    return 0;
}