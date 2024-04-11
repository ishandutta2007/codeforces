#include <bits/stdc++.h>
using namespace std;
#define ll long long
int Try(int x,int n)
{
    for (int i=1;i<=n;i++)
    {
        if (i%2)
        {
            if (x<=1)
                x=1-x;
        }
        else
        {
            if (x==1)x=2;
            else if (x==2)x=1;
        }
    }
    return x;
}
int main()
{
    int n,x;
    cin>>n>>x;
    if (Try(0,n%30)==x)
        cout<<0<<endl;
    else if (Try(1,n%30)==x)
        cout<<1<<endl;
    else cout<<2<<endl;
}