#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long sum=0,mx=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        long  long x;
        cin>>x;
        sum+=x;
        mx=max(mx,x);
    }
    if (sum%2==0 && (sum-mx)>=mx)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}