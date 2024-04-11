#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for (int i=1; i<=n; i++)
            cin>>b[i];
        sort(b+1,b+n+1);
        for (int i=1; i<=n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        for (int i=1; i<=n; i++)
            cout<<b[i]<<" ";
        cout<<"\n";
    }
}