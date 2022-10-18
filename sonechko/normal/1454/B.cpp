#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define pb push_back
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

pair<int,int> a[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    a[n+1].ff=0;
    sort(a+1,a+n+1);
    int ans=-1;
    for (int i=1; i<=n; i++)
        if (a[i].ff!=a[i-1].ff&&a[i].ff!=a[i+1].ff)
    {
        ans=a[i].ss;
        break;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}