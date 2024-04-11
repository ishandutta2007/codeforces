#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N];

void up()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    set<int> st;
    int pos=1;
    ll ans=0;
    for (int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        if (st.find(x)!=st.end())
        {
            st.erase(x);
            ans++;
        } else
        {
            while (a[pos]!=x)
            {
                st.insert(a[pos]);
                pos++;
            }
            ans+=1ll*(st.size()*2+1);
            pos++;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}