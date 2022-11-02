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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=10000000;
vector<int> a[maxn+5];
int n,t1,t2,c1,c2,c3,ans,rc,fc,cs;
int u[maxn+5],hash[maxn+5];

int gcd(int a,int b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

int main()
{
    scanf("%d",&n);
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=n;i++) scanf("%d",&cs),hash[cs]=1;
    t1=trunc(sqrt(maxn*1.5));
    t2=trunc(sqrt(maxn/2));
    for (int i=1;i<=t1;i++)
        for (int j=1;j<=t2;j++)
        {
            c1=i*i+j*j;
            c2=i*i-j*j;
            if (c2<=0) continue;
            c3=2*i*j;
            if ((c1<=maxn)&&(c2<=maxn)&&(hash[c1]+hash[c2]==2)&&(gcd(c1,c2)==1)) a[c1].p_b(c2),a[c2].p_b(c1);
            if ((c1<=maxn)&&(c3<=maxn)&&(hash[c1]+hash[c3]==2)&&(gcd(c1,c3)==1)) a[c1].p_b(c3),a[c3].p_b(c1);
            if ((c2<=maxn)&&(c3<=maxn)&&(hash[c2]+hash[c3]==2)&&(gcd(c2,c3)==1)) a[c2].p_b(c3),a[c3].p_b(c2);
        }
    ans=0;
    for (int i=1;i<=maxn;i++)
        if (hash[i]==1)
        {
            ans++;
            rc=1;fc=1;u[rc]=i;
            hash[i]=0;
            while (rc<=fc)
            {
                for (int j=0;j<a[u[rc]].size();j++)
                    if (hash[a[u[rc]][j]]==1)
                    {
                        hash[a[u[rc]][j]]=0;
                        ++fc;u[fc]=a[u[rc]][j];
                    }
                ++rc;
            }
        }
    cout<<ans<<endl;

    return 0;
}