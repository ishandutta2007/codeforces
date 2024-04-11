#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int f[N],s[N],a[N];

void up()
{
    int n;
    cin>>n;
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (f[a[i]]==0) {f[a[i]]=i; vv.pb(a[i]);}
        s[a[i]]=i;
    }
    int ans=vv.size();
    sort(vv.begin(),vv.end());
    int r=0;
    for (int l=0; l<vv.size(); l++)
    {
        if (r<l) r=l;
        while (r<vv.size()-1&&s[vv[r]]<f[vv[r+1]])
            r++;
        ans=min(ans,(int)vv.size()-(r-l+1));
    }
    for (int i=1; i<=n; i++)
    {
        f[a[i]]=0;
        s[a[i]]=0;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
        up();
}