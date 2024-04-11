#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5 + 11;

int a[N],b[N];

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n,m;
   cin>>n>>m;
   int t1=0,t2=0;
   for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        t1^=a[i];
    }
   for (int i=1; i<=m; i++)
    {
        cin>>b[i];
        t2^=b[i];
    }
    if (t1!=t2) {cout<<"NO"<<endl; return 0;}
    cout<<"YES\n";
    cout<<(a[1]^t2^b[1])<<" ";
    for (int j=2; j<=m; j++)
        cout<<b[j]<<" ";
    cout<<"\n";
    for (int i=2; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        if (j==1) cout<<a[i]<<" "; else cout<<0<<" ";
        cout<<"\n";
    }
}