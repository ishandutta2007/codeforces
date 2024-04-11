#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
const int N = 1e5 + 11;

ll s[N],a[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    multiset<int> st;
    for (int i=1; i<=n; i++)
        dp[i]=s[i];
    for (int i=1; i<m; i++)
        st.insert(a[i]);
    st.insert(0);
    for (int i=m; i<=n; i++)
    {
        st.erase(st.find(a[i-m]));
        st.insert(a[i]);
        ll d=*st.begin();
        dp[i]=min(dp[i-1]+a[i],dp[i-m]+s[i]-s[i-m]-d);
    }
    cout<<dp[n]<<endl;
}