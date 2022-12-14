#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,v;
    cin>>n>>v;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x]+=y;
        b[x+1]+=y;
    }
    int ret=0;
    for (int i=1;i<=3001;i++)
    {
        int k=v;
        if (b[i]>=v)ret+=v,k=0;
        else k-=b[i],ret+=b[i];
        if (a[i]>=k)ret+=k,b[i+1]-=k,k=0;
        else ret+=a[i],b[i+1]-=a[i],k-=a[i];
    }
    cout<<ret<<endl;
}