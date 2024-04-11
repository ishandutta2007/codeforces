#include<bits/stdc++.h>
using namespace std;
int main()
{
    int maxa=0,maxb=0,n,a,num;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a;
        if (a>maxa)
        {
            maxb=maxa;
            maxa=a;
            num=i;
        }
        else if (a>maxb)
        {
            maxb=a;
        }
    }
    cout<<num<<" "<<maxb;
}