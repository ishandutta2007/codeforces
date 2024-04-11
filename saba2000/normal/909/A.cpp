#include<bits/stdc++.h>
using namespace std;
main()
{
    string a,b;
    cin>>a>>b;
    int i=1;
    cout<<a[0];
    while(a[i]<b[0] && i<a.size())
        {cout<<a[i];i++;}
    cout<<b[0];
}