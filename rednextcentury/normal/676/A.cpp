#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int a,b;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x==1)
            a=i;
        if (x==n)
            b=i;
    }
    cout<<max(max(a,b),max(n-1-a,n-1-b))<<endl;
}