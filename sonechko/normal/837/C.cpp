#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 100 + 11;



int x[N],y[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    for (int i=1; i<=n; i++)
        cin>>x[i]>>y[i];
    int ans=0;
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
    {
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[i],y[i]);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[j],y[j]);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[i],y[i]);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[j],y[j]);
        swap(a,b);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[i],y[i]);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[j],y[j]);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[i],y[i]);
        if (x[i]+x[j]<=a&&y[i]<=b&&y[j]<=b) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        swap(x[j],y[j]);
    }
    cout<<ans<<endl;
}