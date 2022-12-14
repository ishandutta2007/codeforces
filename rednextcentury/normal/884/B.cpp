#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mp make_pair
#define ll long long
int main()
{
    fast;
    int n;
    long long k;
    cin>>n>>k;
    long long sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    if (k-sum==n-1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}