#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int k[N],use[N];
vector<pair<int,int> > v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,kk;
    cin>>n>>m>>kk;
    vector<pair<int,int> > vv;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        k[l]++;
        k[r]++;
        vv.pb(mp(l,r));
        v[l].pb(mp(r,i));
        v[r].pb(mp(l,i));
    }
    set<pair<int,int> > st;
    for (int i=1; i<=n; i++)
        st.insert(mp(k[i],i));
    vector<int> ans;
    for (int i=m; i>=1; i--)
    {
        ///cout<<"after "<<i<<endl;
        while (st.size()>0)
        {
            pair<int,int> p=*st.begin();
            if (p.ff>=kk) break;
            int l=p.ss;
            use[l]=1;
            ///cout<<"-"<<l<<endl;
            st.erase(p);
            for (int j=0; j<v[l].size(); j++)
                if (v[l][j].ss<=i&&use[v[l][j].ff]==0)
            {
                int to=v[l][j].ff;
                st.erase(mp(k[to],to));
                k[to]--;
                st.insert(mp(k[to],to));
            }
        }
        ans.pb(st.size());
        int l=vv.back().ff;
        int r=vv.back().ss;
        vv.pop_back();
        if (use[l]==0&&use[r]==0)
        {
            st.erase(mp(k[l],l));
            k[l]--;
            st.insert(mp(k[l],l));
            st.erase(mp(k[r],r));
            k[r]--;
            st.insert(mp(k[r],r));
        }
    }
    for (int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<"\n";
}