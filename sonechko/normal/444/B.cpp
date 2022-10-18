#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int MOD = 998244353;
const int N = 1e5 + 11;

int n,d,x;
int a[N],b[N];
bitset<N> a1,a2,a3;
int ans[N],pos[N];

int getnext()
{
    x = (x * 1ll * 37 + 10007ll) % 1000000007;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>d>>x;
    for (int i=0; i<n; i++)
        a[i]=i+1;
    for (int i=0; i<n; i++)
        swap(a[i],a[getnext()%(i+1)]);
    for (int i=0; i<n; i++)
        if (i<d) b[i]=1; else b[i]=0;
    for (int i=0; i<n; i++)
        swap(b[i],b[getnext()%(i+1)]);
    vector<int> v;
    for (int i=0; i<n; i++)
    {
        if (b[i]) v.pb(i);
        pos[a[i]]=i;
    }
    for (int i=0; i<n; i++)
    {
        int ans=0;
        for (int j=n; j>=max(0,n-100); j--)
            if (pos[j]<=i&&b[i-pos[j]]==1) {ans=j; break;}
        if (ans==0)
        {
            for (int j=0; j<v.size(); j++)
                if (v[j]<=i) ans=max(ans,a[i-v[j]]);
        }
        cout<<ans<<"\n";
    }
}