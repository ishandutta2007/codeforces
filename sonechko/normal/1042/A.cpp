#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,m;
    cin>>n>>m;
    int mx=0,mxx=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        mxx=max(mxx,a[i]);
    }
    mxx+=m;
    for (int i=1; i<=n; i++)
        m-=mx-a[i];
    while (m>0)
    {
        m-=n;
        mx++;
    }
    cout<<mx<<" "<<mxx;
}