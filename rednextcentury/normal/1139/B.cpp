#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long ret=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int last=1e9+2;
    for (int i=n;i>=1;i--)
    {
        if (a[i]<last)ret+=a[i],last=a[i];
        else if (last>0)ret+=last-1,last--;
    }
    cout<<ret<<endl;
}