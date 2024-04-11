#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k,x=0;
    cin>>n>>k;
    for (int i=0; i<n*k; i++)
    {
        char p;
        cin>>p;
        if(p!='B' && p!='W' && p!='G') x++;
    }
    if(x) printf("#Color");
    else printf("#Black&White");
}