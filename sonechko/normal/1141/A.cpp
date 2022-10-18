#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if (m%n!=0) {cout<<"-1"<<endl; return 0;}
    int t=m/n;
    int x=0;
    while (t%2==0)
    {
        t/=2;
        x++;
    }
    while (t%3==0)
    {
        t/=3;
        x++;
    }
    if (t!=1) cout<<-1; else cout<<x<<endl;
}