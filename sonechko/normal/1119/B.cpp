#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 11;

int a[N],h;

bool can(int n)
{
    sort(a+1,a+n+1);
    int hh=h;
    for (int i=n; i>=1; i-=2)
    {
        if (a[i]>hh) return 0;
        hh-=a[i];
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>h;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (can(i)) ans=i;
    }
    cout<<ans<<endl;
}