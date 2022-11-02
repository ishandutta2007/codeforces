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

const int maxn=20000000;

bool prime[maxn+1];
int p[maxn/10];
int n,o,cs,c,t;
int biao[10005];

int main()
{
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    o=0;
    for (int i=2;i<=maxn;i++)
    {
        if (prime[i]==0)
        {
            ++o;
            p[o]=i;
        }
        cs=maxn/i;
        for (int j=1;j<=o;j++)
        {
            if (p[j]>cs) break;
            prime[p[j]*i]=1;
            if (i%p[j]==0) break;
        }
    }

    scanf("%d",&n);
    c=n*(n+1)/2;
    if (c%2==0)
    {
        for (int i=1;i<c;i++)
            if ((prime[i]==0)&&(prime[c-i]==0))
            {
                t=i;
                break;
            }
        for (int i=1;i<=n;i++) biao[i]=1;
        for (int i=n;i>=1;i--)
        {
            if (t>=i)
            {
                t-=i;
                biao[i]=2;
            }
        }
    }
    else
    {
        if (prime[c]==0)
        {
            for (int i=1;i<=n;i++) biao[i]=1;
        }
        else
        {
            if (prime[c-2]==0)
            {
                for (int i=1;i<=n;i++) biao[i]=1;
                biao[2]=2;
            }
            else
            {
                for (int i=1;i<c;i++)
                    if ((prime[i]==0)&&(prime[c-3-i]==0))
                    {
                        t=i;
                        break;
                    }
                for (int i=1;i<=n;i++) biao[i]=1;
                for (int i=n;i>=1;i--)
                {
                    if (i==3) continue;
                    if (t>=i)
                    {
                        t-=i;
                        biao[i]=2;
                    }
                }
                biao[3]=3;
            }
        }
    }
    for (int i=1;i<n;i++) printf("%d ",biao[i]);printf("%d\n",biao[n]);

    return 0;
}