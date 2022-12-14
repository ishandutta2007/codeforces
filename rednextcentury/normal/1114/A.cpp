#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x,y,z;
    int g,p,b;
    cin>>x>>y>>z>>g>>p>>b;
    if (g<x)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    g-=x;
    if (g+p>=y && g+p+b>=y+z)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}