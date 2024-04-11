#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int bigp=1000000007;

int fac[1000005],f[1005];
int m,n,k,ans,c1,c2,c3;

int powc(int a,int b,int p)
{
    if (b==0) return 1;
    int d=powc(a,b/2,p);
    d=(LL)d*d%p;
    if (b%2==1) d=(LL)d*a%p;
    return d;
}

int combine(int m,int n)
{
    int c=(LL)fac[n]*fac[m-n]%bigp;
    int d=(LL)fac[m]*powc(c,bigp-2,bigp)%bigp;
    return d;
}

int main()
{
    cin>>m>>n>>k;
    if (n==1)
    {
        cout<<powc(k,m,bigp)<<endl;
        return 0;
    }
    fac[0]=1;
    for (int i=1;i<=k;i++) fac[i]=(LL)fac[i-1]*i%bigp;
    memset(f,0,sizeof(f));
    for (int i=1;i<=m;i++)
    {
        f[i]=powc(i,m,bigp);
        for (int j=1;j<i;j++)
            f[i]=(f[i]-(LL)f[j]*combine(i,j)%bigp+bigp)%bigp;
    }
    ans=0;
    for (int i=1;i<=m;i++)
        for (int j=0;j<=i;j++)
        {
            c1=(LL)f[i]*combine(k,i)%bigp;
            c2=((LL)f[i]*combine(i,j)%bigp)*(LL)combine(k-i,i-j)%bigp;
            c3=powc(j,m*(n-2),bigp);
            ans=(ans+((LL)c1*c2%bigp)*(LL)c3%bigp)%bigp;
            //cout<<i<<" "<<j<<" "<<ans<<endl;
        }
    cout<<ans<<endl;

    return 0;
}