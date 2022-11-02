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

const int maxn=100005;

int n,o1,o2,c1,c2,flag,wc,cs;
int f1[maxn],g1[maxn],f2[maxn],g2[maxn],hash[maxn];

int main()
{
    scanf("%d",&n);
    o1=0;o2=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&flag,&wc);
        if (flag==0)
            ++o1,f1[o1]=wc,g1[o1]=i;
        else
            ++o2,f2[o2]=wc,g2[o2]=i;
    }
    c1=1;c2=1;
    memset(hash,0,sizeof(hash));
    while ((c1<=o1)&&(c2<=o2))
    {
        cs=min(f1[c1],f2[c2]);
        printf("%d %d %d\n",g1[c1],g2[c2],cs);
        f1[c1]-=cs;f2[c2]-=cs;
        hash[g1[c1]]=1;
        hash[g2[c2]]=1;
        if (f1[c1]==0) ++c1; else ++c2;
    }
    if (c1>o1)
    {
        for (int i=c2;i<=o2;i++)
            if (hash[g2[i]]==0) printf("%d %d %d\n",g1[o1],g2[i],0);
    }
    if (c2>o2)
    {
        for (int i=c1;i<=o1;i++)
            if (hash[g1[i]]==0) printf("%d %d %d\n",g1[i],g2[o2],0);
    }

    return 0;
}