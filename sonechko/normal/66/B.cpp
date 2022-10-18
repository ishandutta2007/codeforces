#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int res=1;
        for (int j=i-1; j>=1; j--)
            if (a[j]<=a[j+1]) res++; else break;
        for (int j=i+1; j<=n; j++)
            if (a[j]<=a[j-1]) res++; else break;
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}