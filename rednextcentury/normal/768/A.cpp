#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    int mn=1000000000,mnn=0,mxn=0,mx=-1000000000;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]<mn)mn=a[i],mnn=1;
        else if (a[i]==mn)mnn++;
        if (a[i]>mx)mx=a[i],mxn=1;
        else if (a[i]==mx)mxn++;
    }
    cout<<max(0,n-mnn-mxn)<<endl;
}