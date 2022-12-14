#include<bits/stdc++.h>

using namespace std;
int num[3];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        num[t]+=x-y;
    }
    for (int i=1;i<=2;i++)
    {
    if (num[i]>=0)
        cout<<"LIVE"<<endl;
    else
        cout<<"DEAD"<<endl;
    }
}