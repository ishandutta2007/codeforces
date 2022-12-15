#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    long long z=0,o=0,oz=0,zz=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]=='0')z++;
        if (a[i]=='1')o++;
        if (a[i]=='0' && b[i]=='0')zz++;
        if (a[i]=='1' && b[i]=='0')oz++;
    }
    cout<<oz*z+zz*o-oz*zz<<endl;
}