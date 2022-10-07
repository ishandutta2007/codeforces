#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k,x=0;
    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        int p;
        cin>>p;
        if(p>k) x++;
    }
    cout<<x+n;
}