#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int gl[N];

int glava(int l)
{
    if (l==gl[l]) return l;
    return gl[l]=glava(gl[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1; i<=n; i++)
        gl[i]=i;
    for (int i=1; i<=m; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        vv.pb(mp(k,mp(l,r)));
    }
    sort(vv.begin(),vv.end());
    ll ans=0;
    for (int j=0; j<vv.size(); j++)
    {
        if (j==0||vv[j-1].ff!=vv[j].ff)
    {
        for (int t=j; t<vv.size(); t++)
            if (vv[t].ff==vv[j].ff)
        {
            int l=vv[t].ss.ff,r=vv[t].ss.ss;
            if (glava(l)!=glava(r)) ans++;
            //cout<<"+ "<<vv[t].ff<<"  "<<l<<" "<<r<<endl;
        } else break;
    }

        int l=vv[j].ss.ff,r=vv[j].ss.ss;
        int k=vv[j].ff;
        int x=glava(l),y=glava(r);
        if (x!=y)
        {
            gl[x]=y;
            //cout<<"- "<<l<<" "<<r<<endl;
            ans--;
        }

    }
    cout<<ans<<endl;

}