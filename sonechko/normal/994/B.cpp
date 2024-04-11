#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long

const int N = 1e5 + 11;

pair<int,pair<int,int> > a[N];
ll res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    cin>>a[i].ff;
    for (int i=1; i<=n; i++)
    cin>>a[i].ss.ff;
    for (int i=1; i<=n; i++)
    a[i].ss.ss=i;
    sort(a+1,a+n+1);
    multiset<int> st;
    ll sum=0;
    for (int i=1; i<=n; i++)
    {
              res[a[i].ss.ss]=sum+1ll*a[i].ss.ff;
              if (st.size()<k) {st.insert(a[i].ss.ff); sum+=1ll*a[i].ss.ff;} else 
              if (k>0&&*st.begin()<a[i].ss.ff) {sum-=*st.begin();
              st.erase(st.find(*st.begin())); sum+=1ll*a[i].ss.ff; st.insert(a[i].ss.ff);}
    }
    for (int i=1; i<=n; i++)
    cout<<res[i]<<" ";
    cout<<endl;
}