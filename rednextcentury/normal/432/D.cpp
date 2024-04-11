# include <iostream>
# include <algorithm>
# include <vector>
# include <stdio.h>
using namespace std;
string s;
int n;
int a[1000000];
int p[1000000];
int is[1000000];
void PRE()
{
    int i=0,j=-1;
    p[i]=j;
    while(i<n)
    {
        while (j>=0  && s[i]!=s[j])
            j=p[j];
        j++,i++;
        p[i]=j;
    }
}
int main()
{
    cin>>s;
    n=s.length();
    PRE();
    int tot=0;
    int v=p[n];
    while (v>0)
    {
        a[tot++]=v;
        v=p[v];
    }
    for (int i=1;i<=n;i++)
        is[i]=1;
    cout<<tot+1<<endl;
    for (int i=n;i>=1;i--)
        is[p[i]]+=is[i];
    for (int i=tot-1;i>=0;i--)
    {
        cout<<a[i]<<" "<<is[a[i]]<<endl;
    }
    cout<<n<<" "<<1<<endl;
}