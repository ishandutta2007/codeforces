#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    int i=0;
    int op=0;
    if (a[0]==0)
        op++;
    while(a[0+op]!=b[i])
        i++;
    for (int j=0;j<n;j++)
    {
        if (a[j]==0)continue;
        if (i>=n)i-=n;
        if (b[i]==0)i++;
        if (i>=n)i-=n;
        if (a[j]!=b[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
        i++;
    }
    cout<<"YES"<<endl;
}