#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

ll s[N],ans[N];
map<ll,bool> use;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int nn;
    cin>>nn;
    int n=0;
    for (int i=1; i<=nn; i++)
    {
        ll c;
        cin>>c;
        if (use[c]==0) {use[c]=1; n++; s[n]=c;}
    }
    sort(s+1,s+n+1);
    set<pair<ll,int> > st;
    for (int j=2; j<=n; j++)
        st.insert(mp(s[j]-s[j-1],j));
    int m;
    cin>>m;
    vector<pair<ll,int> > vv;
    for (int i=1; i<=m; i++)
    {
        ll l,r;
        cin>>l>>r;
        vv.pb(mp(r-l,i));
    }
    sort(vv.begin(),vv.end());
    ll sum=n,kol=n;
    for (int j=0; j<vv.size(); j++)
    {
        ll len=vv[j].ff;
        while (st.size()>0)
        {
            pair<ll,int> p=*st.begin();
            if (p.ff>len) break;
            st.erase(p);
            int num=p.ss;
            sum+=s[num]-s[num-1]-1;
            kol--;
        }
        ans[vv[j].ss]=sum+kol*len;
    }
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}