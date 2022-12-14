
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin>>n>>a;
    int t=1;
    int l=n,r=1;
    while(l!=a && r!=a)
    {
        t++;
        r+=2,l-=2;
    }
    cout<<t<<endl;
}