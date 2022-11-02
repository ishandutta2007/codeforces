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
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int n,a[30];
vector<PII> ans;

int other(int a,int b)
{
    if (a>b) swap(a,b);
    if ((a==1)&&(b==2)) return 3;
    if ((a==1)&&(b==3)) return 2;
    if ((a==2)&&(b==3)) return 1;
    return 0;
}

void search(int l,int r,int n,int flag)
{
    int t=other(l,r),k=n;
    while ((k>1)&&(a[k-1]==a[k])) --k;
    if (flag==0)
    {
        if (k==n) search(l,r,n,1); else
            if (k==1)
            {
                for (int i=1;i<n;i++) ans.p_b(m_p(l,t));
                ans.p_b(m_p(l,r));
                for (int i=1;i<n;i++) ans.p_b(m_p(t,r));
            }
            else
            {
                search(l,r,k-1,1);
                for (int i=1;i<=n-k+1;i++) ans.p_b(m_p(l,t));
                search(r,l,k-1,1);
                for (int i=1;i<=n-k+1;i++) ans.p_b(m_p(t,r));
                search(l,r,k-1,0);
            }
    }
    else
    {
        if (k==1)
        {
            for (int i=1;i<=n;i++) ans.p_b(m_p(l,r));
        }
        else
        {
            search(l,t,k-1,1);
            for (int i=1;i<=n-k+1;i++) ans.p_b(m_p(l,r));
            search(t,r,k-1,1);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=n;i>=1;i--) scanf("%d",&a[i]);

    search(1,3,n,0);

    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].w1,ans[i].w2);

    return 0;
}