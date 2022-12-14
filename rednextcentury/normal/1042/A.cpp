#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int mn=1000000;
    int mx=0;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        mn=min(mn,x);
        mx=max(mx,x);
    }
    cout<<max((sum+m)/n+(((sum+m)%n)>0),mx)<<' '<<mx+m<<endl;
}