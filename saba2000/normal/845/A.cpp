#include<bits/stdc++.h>
using namespace std;
int a[100009];
main()
{
    int n;
    cin>>n;
    for (int i=0; i<2*n; i++)
        cin>>a[i];
        sort(a,a+2*n);
        if(a[n]==a[n-1]) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
}