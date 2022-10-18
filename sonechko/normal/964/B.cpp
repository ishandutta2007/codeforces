#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
#define ll long long
const int N = 4e5 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b,c,t;
    cin>>n>>a>>b>>c>>t;
    if (c-b>0)
    {
              ll ans=0;
              for (int i=1; i<=n; i++)
              {
                        int l;
                        cin>>l;
                        kol[l]++;
                        ans+=a-(t-l)*b;
              }
              for (int i=1; i<t; i++)
              {
                        kol[i]+=kol[i-1];
                        ans+=kol[i]*c;
              }
              cout<<ans<<endl;
              return 0;
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
              int l;
              cin>>l;
              ans+=a;
    }
    cout<<ans<<endl;
}