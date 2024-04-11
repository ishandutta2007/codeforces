#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 5e5 + 11;
vector<int> v[N];
int use[N],a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=n; i>=1; i--)
    v[a[i]].pb(i);
    for (int i=1; i<=n; i++)
        if (v[a[i]].size()==1) use[i]=1;
    int l=1;
    int ans=0;
    for (int j=1; j<=n; j++)
    if (v[j].size()==1) {} else
    if (v[j].size()>1)
    {
        int p=v[j].back();
        v[j].pop_back();
        use[p]=1;
    } else
    {
        while (use[l]==1)
            l++;
        ans++;
        int p=a[l];
        v[p].pop_back();
        use[l]=1;
        a[l]=j;
        if (v[p].size()==1&&p>j)
        {
            use[v[p][0]]=1;
        }
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}