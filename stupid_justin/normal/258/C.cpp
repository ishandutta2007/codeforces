#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MOD 1000000007
long long a[MAXN+10],n,p[MAXN+10],cnt,ans;
void Read(long long &x){
    char c;
    while((c=getchar())&&c!=EOF){
        if(c>='0'&&c<='9'){
            x=c-'0';
            while((c=getchar())&&c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
    }
}
void isfactor(long long n){
    long long t=sqrt(n+0.5),i;
    cnt=0;
    for(i=1;i<=t;i++)
        if(n%i==0)
            p[++cnt]=i;
    i=cnt;
    cnt*=2;
    if(t*t==n)
        cnt--,i--;
    for(;i;i--){
        p[cnt-i+1]=n/p[i];
    }
}
long long pow(long long a,long long b){
    long long ret=1;
    while(b){
        if(b&1)
            ret=ret*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ret;
}
int main()
{
    long long i,j,k,t,s;
    Read(n);
    for(i=1;i<=n;i++)
        Read(a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=a[n];i++){
        isfactor(i);
        t=0;
        s=1;
        for(j=2;j<=cnt;j++){
            k=lower_bound(a+t+1,a+n+1,p[j])-a-1;
            s=s*pow(j-1,k-t)%MOD;
            t=k;
        }
        s=s*(pow(cnt,n-t)+MOD-pow(cnt-1,n-t))%MOD;      
        ans=(ans+s)%MOD;
    }
    printf("%I64d\n",ans);
}