#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int s=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s+=x;
    }
    if ((n==1 && s==1) || (n>1 && s==n-1))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}