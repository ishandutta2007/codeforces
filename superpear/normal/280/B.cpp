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

const int maxn=100005;
int a[maxn],base[maxn],st[maxn][18],next[maxn];
int n,ans;

int getmax(int l,int r)
{
    int c=base[r-l+1];
    return max(st[l][c],st[r-(1<<c)+1][c]);
}

void doit()
{
    memset(st,0,sizeof(st));
    for (int i=n;i>=1;i--)
    {
        st[i][0]=a[i];
        for (int j=1;j<=16;j++)
            if (i+(1<<(j-1))<=n) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
    int left,right,mid,t;
    memset(next,0,sizeof(next));
    for (int i=1;i<=n;i++)
    {
        left=i+1;right=n;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (getmax(i+1,mid)>a[i]) right=mid-1; else left=mid+1;
        }
        next[i]=left;
    }
    //for (int i=1;i<=n;i++) cout<<next[i]<<" ";cout<<endl;
    for (int i=1;i<n;i++)
        if (a[i+1]<a[i])
        {
            t=i+1;
            while (t<=n)
            {
                ans=max(ans,a[i]^a[t]);
                t=next[t];
                if (t>n) break;
                if (a[t]>a[i])
                {
                    ans=max(ans,a[i]^a[t]);
                    break;
                }
            }
        }
}

int main()
{
    base[1]=0;
    for (int i=2;i<=100000;i++) base[i]=base[i/2]+1;

    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    ans=0;
    doit();
    reverse(a+1,a+n+1);
    doit();
    printf("%d\n",ans);

    return 0;
}