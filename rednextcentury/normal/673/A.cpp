#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100]={0};
    a[n+1]=90;
    for (int i=1;i<=n+1;i++)
    {
        cin>>a[i];
        if (a[i]-a[i-1]>15)
        {
            cout<<a[i-1]+15<<endl;
            return 0;
        }
    }
    cout<<90<<endl;
}