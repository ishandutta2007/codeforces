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

string s1,s2,s3;
int f[maxn*2],z1[maxn],z2[maxn];
int n,t,r;
char ch;

void extend_kmp(string s)
{
    int right,n,c;
    memset(f,0,sizeof(f));
    right=1,c=1;
    n=s.size();
    for (int i=2;i<=n;i++)
    {
        if (right<i-1) right=i-1;
        f[i]=min(right-i+1,f[i-c+1]);
        if ((f[i]+i-1==right)&&(s[f[i]+i-1]==s[f[i]]))
        {
            c=i;
            while ((f[i]+i<=n)&&(s[f[i]+i-1]==s[f[i]])) ++f[i],++right;
        }
    }
}

int main()
{
    s1="",s2="";
    while (true)
    {
        ch=getchar();
        if ((int(ch)>=32)&&(int(ch)<=126)) s1+=ch; else break;
    }
    while (true)
    {
        ch=getchar();
        if ((int(ch)>=32)&&(int(ch)<=126)) s2+=ch; else break;
    }
    if (s1.size()!=s2.size())
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    n=s1.size();
    if (n==1)
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    s3="";
    for (int i=n-1;i>=0;i--) s3+=s1[i];
    extend_kmp(s2+"><~"+s1);
    for (int i=1;i<=n;i++)
        z1[i]=f[n+3+i];
    extend_kmp(s3+"><~"+s2);
    for (int i=1;i<=n;i++)
        z2[i]=f[n+3+i];
    t=0;
    while ((t<n)&&(s1[t]==s2[n-t-1])) ++t;
    if (t==n)
    {
        cout<<n-2<<" "<<n-1<<endl;
        return 0;
    }
    r=1;
    for (int i=t;i>=1;i--)
    {
        while ((r<n)&&(r+z2[r]-1<n-i)) ++r;
        if (r+z2[r]-1>=n-i)
        {
            if (r<=z1[i+1]+1)
            {
                cout<<i-1<<" "<<i+r-1<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1"<<endl;

    return 0;
}