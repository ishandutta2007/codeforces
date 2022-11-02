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

const int bigp=1000000007;
const int maxn=1100001;

int p2[maxn],a[maxn],f[maxn][21];
int N,S,e,ans,cs;

int main()
{
    p2[0]=1;
    for (int i=1;i<=1000000;i++) p2[i]=p2[i-1]*2%bigp;

    S=1048575;
    scanf("%d",&N);
    memset(a,0,sizeof(a));
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&cs);
        ++a[S-cs];
    }
    for (int i=0;i<=S;i++) f[i][0]=a[i];
    for (int i=1;i<=20;i++)
        for (int j=0;j<=S;j++)
        {
            f[j][i]=f[j][i-1];
            if ((j>>(i-1))%2==1) f[j][i]+=f[j-(1<<(i-1))][i-1];
        }
    ans=0;
    for (int i=0;i<=S;i++)
    {
        e=0;
        for (int j=1;j<=20;j++) e+=(i>>(j-1))%2;
        if (e%2==0) ans+=p2[f[S-i][20]]; else ans-=p2[f[S-i][20]];
        ans=ans%bigp;
        ans=ans+bigp;
        ans=ans%bigp;
    }
    cout<<ans<<endl;

    return 0;
}