#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 2e5 + 11;

ll sum[N],a[N];

map<ll,bool> use;
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        use[sum[i]]=1;
    }
    ll p=sum[n];
    if (p%2==1) {cout<<"NO"<<endl; return 0;}
    for (int i=1; i<=n; i++)
    if (a[i]>p/2) {cout<<"NO"<<endl; return 0;}
    for (int i=1; i<=n; i++)
        if (sum[i-1]<=p/2+a[i]&&use[p/2+a[i]]==1) {cout<<"YES"<<endl; return 0;}
    for (int i=1; i<=n; i++)
    if (sum[i-1]>=p/2-a[i])
    {
        if (use[p/2-a[i]]==1) {cout<<"YES"<<endl; return 0;}
    }
     cout<<"NO"<<endl;
}