#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

const long long k=997;
long long h[1000010],p[1000010],s[1000010];
long long h2;
string s1,s2;
int ansk=0;
int ans[1000010];

int main()
{
    cin>>s1;
    cin>>s2;
    int n1=s1.length(),n2=s2.length();
    h[0]=1;
    for (int i=1;i<=max(n1,n2)+100;i++) h[i]=h[i-1]*k;
    h2=s2[0];
    for (int i=1;i<n2;i++) h2=h2*k+s2[i];
    p[0]=0;
    for (int i=1;i<=n1;i++) p[i]=p[i-1]*k+s1[i-1];
    s[n1]=0;
    for (int i=n1-1;i>=0;i--) s[i]=s1[i]*h[n1-i-1]+s[i+1];

    for (int i=0;i<=n1;i++)
        if (p[i]*h[n1-i-1]+s[i+1]==h2) ans[ansk++]=i+1;

    printf("%d\n",ansk);
    for (int i=0;i<ansk;i++) printf("%d ",ans[i]);
    return 0;
}