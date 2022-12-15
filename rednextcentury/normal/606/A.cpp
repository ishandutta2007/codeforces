#include <bits/stdc++.h>
using namespace std;
int a[100];
int b[100];
int main()
{
    int ans=0;
    for (int i=0;i<3;i++) cin>>a[i];
    for (int i=0;i<3;i++) cin>>b[i];
    for (int i=0;i<3;i++)
    {
        if (a[i]<b[i]) ans-=b[i]-a[i];
        else ans+=(a[i]-b[i])/2;
    }
    if (ans>=0) cout<< "Yes"<<endl;
    else cout<<"No"<<endl;
}