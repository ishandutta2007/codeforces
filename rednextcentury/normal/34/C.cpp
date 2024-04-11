# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
int a[1000];
int s[1001];
int e[1001];
int tot;
int n;
void stupid_input()
{
    string h;
    cin>>h;
    int m=h.length();
    int i=0;
    for (int j=0;j<m;j++)
    {
        if (h[j]==',') i++;
        else a[i]=a[i]*10+h[j]-'0';
    }
    n=i+1;
}
int main()
{
    stupid_input();
    sort(a,a+n);
    int l=a[0],r=a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]-a[i-1]==0)
            continue;
        if (a[i]-a[i-1]==1)
        {
            r++;
            continue;
        }
        else
        {
            s[tot]=l,e[tot++]=r;
            l=a[i],r=a[i];
        }
    }
    for (int i=0;i<tot;i++)
    {
        if (s[i]==e[i])
            cout<<s[i];
        else
            cout<<s[i]<<"-"<<e[i];
        cout<<',';
    }
    if (l==r)
            cout<<r;
        else
            cout<<l<<"-"<<r;
    cout<<endl;
}