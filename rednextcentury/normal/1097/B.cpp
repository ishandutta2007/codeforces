#include <bits/stdc++.h>

using namespace std;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for (int j=0;j<n;j++)
        {
            if ((1<<j)&i)sum+=a[j];
            else sum-=a[j];
            sum=(sum+360)%360;
        }
        if (sum==0) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}