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
#include <ctime>

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
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=300005;

PII a[maxn];
LL sum[maxn];
int N,K,st,cs;
LL ans,nowans;

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&cs);
        a[i]=m_p(cs,i);
    }
    sort(a+1,a+N+1);
    scanf("%d",&K);

    sum[0]=0;
    for (int i=1;i<=N;i++) sum[i]=sum[i-1]+a[i].w1;

    nowans=0;
    for (int i=2;i<=K;i++)
        nowans+=(LL)a[i].w1*(i-1)-sum[i-1];
    ans=nowans;
    st=1;

    for (int i=K+1;i<=N;i++)
    {
        nowans+=(LL)a[i].w1*(K-1)-(sum[i-1]-sum[i-K]);
        nowans-=(sum[i-1]-sum[i-K])-(LL)a[i-K].w1*(K-1);
        if (nowans<ans)
        {
            ans=nowans;
            st=i-K+1;
        }
    }
    for (int i=st;i<=st+K-2;i++) printf("%d ",a[i].w2);
    printf("%d\n",a[st+K-1].w2);

    return 0;
}