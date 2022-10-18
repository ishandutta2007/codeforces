#include<bits/stdc++.h>
using namespace std;
#define ld long double
int main()
{
    int n,m;
    cin>>n>>m;
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        sum+=l;
    }
    for (int k=0; k<=100000; k++)
    {
        ld ss=(ld)(sum+m*k)/(ld)(n+k);
        if (ss>=(ld)m-0.500001) {cout<<k<<endl; return 0;}
    }
}