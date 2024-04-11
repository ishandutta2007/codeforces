#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int L=1,R=n;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        if (u>v)swap(u,v);
        L=max(L,u);
        R=min(R,v);
    }
    cout<<max(0,R-L)<<endl;
}