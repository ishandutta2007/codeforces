#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    int ans=x;
    for (int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        if (y==x)ans++;
        if (y<x)ans--;
    }
    cout<<ans<<endl;
}