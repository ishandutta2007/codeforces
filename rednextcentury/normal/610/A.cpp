#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n%2)
        cout<<0<<endl;
    else
    {
        n/=2;
        if (n%2==0)
            cout<<n/2-1<<endl;
        else
            cout<<n/2<<endl;
    }
}