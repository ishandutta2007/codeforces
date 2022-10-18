#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (n==1&&m==1) return cout<<0, 0;
    if (n==1)
    {
        for (int i=1; i<=m; i++)
            cout<<i+1<<" ";
        cout<<"\n";
        return 0;
    }
    if (m==1)
    {
        for (int i=1; i<=n; i++)
            cout<<i+1<<"\n";
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            int x=i;
            int y=n+j;
            cout<<(x*y)<<" ";
        }
        cout<<"\n";
    }
}
/**

**/