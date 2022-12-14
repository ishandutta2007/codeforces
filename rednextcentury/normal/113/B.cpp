#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<map>
using namespace std;
bool start[1000000];
bool finish[1000000];
long long a[10000000];
int main()
{
    int n,m1,m2;
    string k;
    string s,e;
    cin>>k>>s>>e;
    n=k.length();
    m1=s.length();
    m2=e.length();
    for (int i=0;i<=n-m1;i++)
    {
        if (k.substr(i,m1)==s)
            start[i]=1;
    }
    for (int i=m2-1;i<n;i++)
    {
        if (k.substr(i-m2+1,m2)==e)
            finish[i]=1;
    }
    int tot=0;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (start[i]==0)
            continue;
        long long l=0;
        for (int x=i;x<n;x++)
        {
            l=l*3541+k[x];
            if (finish[x] && x-i+1>=m1 && x-i+1>=m2)
            {
                a[tot++]=l;
            }
        }
    }
    sort(a,a+tot);
    ans=min(1,tot);
    for (int i=1;i<tot;i++)
        if (a[i]!=a[i-1]) ans++;
    cout<<ans<<endl;
}