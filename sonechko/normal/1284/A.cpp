#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

string a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    int q;
    cin>>q;
    while (q--)
    {
        int x;
        cin>>x;
        int p1=x%n;
        if (p1==0) p1=n;
        int p2=x%m;
        if (p2==0) p2=m;
        cout<<a[p1]<<b[p2]<<"\n";
    }
}