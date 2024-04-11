#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int j=0; j<=n; j++)
        if (a[j]==0)
    {
        int k=0;
        for (int p=0; p<=j; p++)
            if (a[p]==1) k++;
        for (int p=j+1; p<=n; p++)
            if (a[p]==0) k++;
        ans=max(ans,n-k);
    }
    cout<<ans<<endl;
}