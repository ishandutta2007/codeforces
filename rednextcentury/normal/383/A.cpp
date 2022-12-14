#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll num=0,ret=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==1)num++;
        else ret+=num;
    }
    cout<<ret<<endl;
}