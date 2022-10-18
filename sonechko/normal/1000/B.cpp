#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    n++;
    a[n]=m;
    int res=0;
    for (int i=1; i<=n; i++)
        if (i%2==1) res+=a[i]-a[i-1];
    int ans=res,res1=0;
    for (int i=1; i<=n; i++)
    {
        if (i%2==1) res1+=a[i]-a[i-1];
        if (i%2==1&&a[i]>a[i-1]+1)
        {
            //cout<<i<<" "<<m<<"-"<<a[i]<<"-"<<res-res1<<"+"<<res1-1<<endl;
            ans=max(ans,m-a[i]-(res-res1)+res1-1);
        }
        if (i%2==1&&a[i]<a[i+1]-1&&i!=n)
        {
            //cout<<i<<" "<<m<<"-"<<a[i]<<"-"<<res-res1<<"+"<<res1-1<<endl;
            ans=max(ans,m-a[i]-(res-res1)+res1-1);
        }
    }
    cout<<ans<<endl;
}

/**
3 10
4 6 7

2 12
1 10


**/