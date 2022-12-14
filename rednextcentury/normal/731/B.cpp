#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]%2 && a[i+1]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else if (a[i]%2)
            a[i+1]--;
    }
    cout<<"YES"<<endl;
}