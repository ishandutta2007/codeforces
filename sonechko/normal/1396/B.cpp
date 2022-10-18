#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

int n,a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int sum=0,mx=0;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        if (sum%2==1||mx>sum-mx) cout<<"T\n"; else cout<<"HL\n";
    }
}