#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int s[1000001];
int e[1000001];
int num[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if (s[x]==0)
            s[x]=i;
        e[x]=i;
        num[x]++;
    }
    int mx=0;
    int l=1,r=n;
    for (int i=0;i<=1000000;i++)
    {
        if (num[i]>mx)
        {
            mx=num[i];
            l=s[i];
            r=e[i];
        }
        else if (num[i]==mx)
        {
            if (e[i]-s[i]<r-l)
            {
                l=s[i];
                r=e[i];
            }
        }
    }
    cout<<l<<" "<<r<<endl;
}