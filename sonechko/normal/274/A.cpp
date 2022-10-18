#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 1e5 + 11;

map<int,bool> use;
int a[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for (int i=n; i>=1; i--)
        if (use[a[i]]==0)
    {
        ans++;
        if (a[i]%m==0) use[a[i]/m]=1;
    }
    cout<<ans<<endl;
}