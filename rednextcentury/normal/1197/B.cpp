#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int l,r;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==n)l=i,r=i;
    }
    for (int i=n-1;i>=1;i--)
    {
        if (a[l-1]==i)l--;
        else if (a[r+1]==i)r++;
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}