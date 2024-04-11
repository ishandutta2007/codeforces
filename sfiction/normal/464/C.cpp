/*
ID: Sfiction
OJ: CF
PROB: 464C
*/
#include <cstdio>

const int MAXL=100000+10;
const long long MOD=1000000007;

int n;
char *r;
char que[MAXL*6]="0->";

long long num[10],lg[10];

void Init(){
    r=que+3;
    scanf("%s",r);
    scanf("%d",&n);

    while (*++r);
    for (int i=0;i<n;++i){
        scanf("%s",r);
        while (*++r);
    }
    --r;

    for (int i=0;i<10;++i){
        num[i]=i;
        lg[i]=10;
    }
}

int main(){
    Init();

    for (int i=0;i<=n;++i){
        long long ans=0,sum=1;
        for (;*r!='>';--r){
            ans=(ans+num[*r-'0']*sum)%MOD;
            sum=sum*lg[*r-'0']%MOD;
        }
        r-=2;
        num[*r-'0']=ans;
        lg[*r-'0']=sum;
        --r;
    }
    printf("%I64d",num[0]);
    return 0;
}