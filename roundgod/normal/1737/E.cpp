#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,f[MAXN];
int p2[MAXN],pinv2[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
int main()
{
    p2[0]=pinv2[0]=1;
    for(int i=1;i<=1000000;i++) pinv2[i]=1LL*INV*pinv2[i-1]%MOD;
    for(int i=1;i<=1000000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            puts("1");
            continue;
        }
        f[n]=1; f[1]=0;
        int sum=1,l=n,r=n;
        for(int i=n-1;i>=2;i--)
        {
            while(r-i>=i)
            {
                int cf=(r==n?pinv2[r-i-1]:pinv2[r-i]);
                dec(sum,1LL*cf*f[r]%MOD);
                r--;
            }
            f[i]=sum;
            sum=1LL*INV*sum%MOD;
            add(sum,1LL*INV*f[i]%MOD);
            l=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                puts("0");
                continue;
            }
            int prob=(i==n?1:INV);
            int need=(i+1)/2;
            prob=1LL*prob*pinv2[need-1]%MOD*f[i]%MOD;
            printf("%d\n",prob);
        }
    }
    return 0;
}