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
#include <string>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

string s,t;
int m,n,e,flag,l1,r1;
int f[30][220000];
int a[220000],b[220000];

int main()
{
    cin>>s;
    cin>>t;
    n=s.size();
    m=t.size();
    for (int i=1;i<=26;i++)
    {
        f[i][0]=0;
        for (int j=1;j<=m;j++)
        {
            f[i][j]=f[i][j-1];
            if (t[j-1]-96==i) ++f[i][j];
        }
    }
    e=0;
    for (int i=1;i<=n;i++)
    {
        if ((e<m)&&(t[e]==s[i-1])) ++e;
        a[i]=e;
    }
    e=0;
    for (int i=n;i>=1;i--)
    {
        if ((e<m)&&(t[m-e-1]==s[i-1])) ++e;
        b[i]=e;
    }
    flag=1;
    for (int i=1;i<=n;i++)
    {
        l1=m-b[i]+1;r1=a[i];
        if (f[s[i-1]-96][r1]<=f[s[i-1]-96][l1-1])
        {
            flag=0;
            break;
        }
    }
    if (flag==1) cout<<"Yes"<<endl; else cout<<"No"<<endl;

    return 0;
}