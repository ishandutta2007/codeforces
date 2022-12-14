#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    int mn=1e9;
    int best=-1;
    for (int i=1;i<=n;i++)
    {
        int s,d;
        cin>>s>>d;
        int tim;
        if (s>=t)
            tim = s;
        else
            tim = s+((t-s)/d + ((t-s)%d>0))*d;
        if (tim-t<mn)
        {
            mn=tim-t;
            best=i;
        }
    }
    cout<<best<<endl;
}