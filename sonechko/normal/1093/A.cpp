#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int x;
        cin>>x;
        if (x%2==0) cout<<x/2<<endl; else cout<<(x-3)/2+1<<endl;
    }
}