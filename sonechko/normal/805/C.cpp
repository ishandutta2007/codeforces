#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MOD = 1e9 + 7;
#define mod %MOD
const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=0,l1=1,l2=n;
    for (int i=1; i<n; i++)
    {
        ans+=(l2+l1)%(n+1);
        if (i%2==1) l1++; else l2--;
    }
    cout<<ans<<endl;
}