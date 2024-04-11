#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mn=1000000;
    int x=-1,y=-1;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        if (n%i)continue;
        if (n/i < i)break;
        if (n/i-i<mn)
        {
            mn=n/i-i;
            x=i,y=n/i;
        }
    }
    cout<<x<<' '<<y<<endl;
}