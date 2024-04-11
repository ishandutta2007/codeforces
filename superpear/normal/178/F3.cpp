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

int N,K,cc,len;
char st[1005];
string s[2005];
int a[2005];

vector<int> getdp(int l,int r)
{
    if (l==r)
    {
        vector<int> f;
        f.clear();
        f.p_b(0);
        f.p_b(0);
        return f;
    }
    int minc=maxlongint,mink=0;
    for (int i=l;i<r;i++)
        if (a[i]<minc)
        {
            minc=a[i];
            mink=i;
        }
    vector<int> q1=getdp(l,mink);
    vector<int> q2=getdp(mink+1,r);
    vector<int> f;
    f.clear();
    for (int i=0;i<q1.size()+q2.size()-1;i++) f.p_b(-maxlongint);
    for (int i=0;i<q1.size();i++)
        for (int j=0;j<q2.size();j++)
            f[i+j]=max(f[i+j],q1[i]+q2[j]+minc*i*j);
    return f;
}

int main()
{
    scanf("%d %d",&N,&K);
    for (int i=1;i<=N;i++)
    {
        scanf("%s",st);
        len=strlen(st);
        for (int j=0;j<len;j++) s[i]+=st[j];
    }
    sort(s+1,s+N+1);
    for (int i=1;i<N;i++)
    {
        cc=0;
        for (int j=0;j<min(s[i].size(),s[i+1].size());j++)
            if (s[i][j]==s[i+1][j]) ++cc; else break;
        a[i]=cc;
    }
    vector<int> ans=getdp(1,N);
    printf("%d\n",ans[K]);

    return 0;
}