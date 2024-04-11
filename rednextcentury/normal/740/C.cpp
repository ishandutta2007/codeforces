#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int ret=10000000;
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        ret=min(ret,r-l+1);
    }
    cout<<ret<<endl;
    for (int i=0;i<n;i++)
        cout<<i%ret<<' ';
    cout<<endl;
}