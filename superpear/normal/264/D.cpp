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

const int maxn=1000005;

char s1[maxn],s2[maxn];
int m,n,ann,flag;
int f[7][maxn],sum[7][maxn];
int a[maxn],b[maxn];
LL ans;

int lou(char c)
{
    if (c=='R') return 1;
    if (c=='G') return 2;
    if (c=='B') return 3;
}

int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    m=strlen(s1);
    n=strlen(s2);
    for (int i=1;i<=m;i++)
        a[i]=lou(s1[i-1]);
    for (int i=1;i<=n;i++)
        b[i]=lou(s2[i-1]);
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    for (int i=2;i<=n;i++)
    {
        if ((b[i-1]==1)&&(b[i]==2)) ++f[1][i];
        if ((b[i-1]==1)&&(b[i]==3)) ++f[2][i];
        if ((b[i-1]==2)&&(b[i]==1)) ++f[3][i];
        if ((b[i-1]==2)&&(b[i]==3)) ++f[4][i];
        if ((b[i-1]==3)&&(b[i]==1)) ++f[5][i];
        if ((b[i-1]==3)&&(b[i]==2)) ++f[6][i];
    }
    for (int i=1;i<=6;i++)
    {
        sum[i][1]=0;
        for (int j=2;j<=n;j++)
            sum[i][j]=sum[i][j-1]+f[i][j];
    }
    int left=1,right=1;
    ans=0;
    for (int i=1;i<=m;i++)
    {
        if (i==1) ann==-1; else ann=a[i-1];
        if (b[left]==ann) ++left;
        if (b[right]==ann) ++right;
        if (right>n) right=n;
        while ((right<n)&&(b[right]!=a[i])) ++right;
        if (left<=right)
        {
            ans+=(LL)right-left+1;
            flag=-1;
            if ((a[i]==1)&&(a[i-1]==2)) flag=1;
            if ((a[i]==1)&&(a[i-1]==3)) flag=2;
            if ((a[i]==2)&&(a[i-1]==1)) flag=3;
            if ((a[i]==2)&&(a[i-1]==3)) flag=4;
            if ((a[i]==3)&&(a[i-1]==1)) flag=5;
            if ((a[i]==3)&&(a[i-1]==2)) flag=6;
            if (flag!=-1) ans-=(LL)sum[flag][right]-sum[flag][left-1];
        }
        //cout<<left<<" "<<right<<endl;
    }
    printf("%I64d\n",ans);

    return 0;
}