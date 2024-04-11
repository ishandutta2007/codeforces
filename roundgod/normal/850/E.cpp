#include<bits/stdc++.h>
#define MAXN 21
#define INF 1000000000
#define MOD 1000000007
#define REV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
void FWT(int a[],int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                a[i+j]=(x+y)%MOD,a[i+j+d]=(x-y+MOD)%MOD;     
                //and:a[i+j]=x+y;    
                //or:a[i+j+d]=x+y;    
            }    
}    
void UFWT(int a[],int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                a[i+j]=1LL*(x+y)*REV%MOD,a[i+j+d]=(1LL*(x-y)*REV%MOD+MOD)%MOD;      
                //and:a[i+j]=x-y;    
                //or:a[i+j+d]=y-x;    
            }    
}    
void solve(int a[],int b[],int n)    
{    
    FWT(a,n);    
    FWT(b,n);    
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%MOD;    
    UFWT(a,n);    
}   
int f[(1<<20)],g[(1<<20)];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<(1<<n);i++) 
    {
        f[i]=str[i]-'0';
        g[i]=f[i]^1;
    }
    solve(f,g,(1<<n));
    int ans=0;
    for(int i=0;i<(1<<n);i++)
        add(ans,1LL*f[i]*(1<<__builtin_popcount(i))%MOD);
    ans=3LL*ans%MOD;
    printf("%d\n",ans);
    return 0;
}