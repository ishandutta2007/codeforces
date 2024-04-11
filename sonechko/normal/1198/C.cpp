#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 11;

vector<pair<int,int> > v[N];
int kk[N],use[N];

void up()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=3*n; i++)
    {
        v[i].clear();
        kk[i]=0;
        use[i]=0;
    }
    ll kol=3ll*n*1ll*(3*1ll*n-1ll)/2;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(mp(r,i));
        v[r].pb(mp(l,i));
        kk[l]++;
        kk[r]++;
    }
    set<pair<int,int> > st;
    for (int i=1; i<=n*3; i++)
        st.insert(mp(kk[i],i));
    vector<int> ans;
    while (st.size()>0)
    {
        if ((int)ans.size()==n) break;
        pair<int,int> p=*st.begin();
        st.erase(p);
        int l=p.ss,r=-1;
        for (int j=0; j<v[l].size(); j++)
            if (use[v[l][j].ff]==0&&(r==-1||kk[v[l][j].ff]<kk[r]))
            r=v[l][j].ff;
        if (r!=-1)
        {
            for (int j=0; j<v[l].size(); j++)
                if (v[l][j].ff==r) {ans.pb(v[l][j].ss); break;}
            st.erase(mp(kk[r],r));
            use[l]=1;
            use[r]=1;
            for (int j=0; j<v[l].size(); j++)
                if (use[v[l][j].ff]==0)
            {
                int to=v[l][j].ff;
                st.erase(mp(kk[to],to));
                kk[to]--;
                st.insert(mp(kk[to],to));
            }
            l=r;
            for (int j=0; j<v[l].size(); j++)
                if (use[v[l][j].ff]==0)
            {
                int to=v[l][j].ff;
                st.erase(mp(kk[to],to));
                kk[to]--;
                st.insert(mp(kk[to],to));
            }
        }
    }
    if (ans.size()>=n)
    {
        cout<<"Matching\n";
        for (int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        return;
    }

    st.clear();
    for (int i=1; i<=3*n; i++)
    {
        kk[i]=v[i].size();
        use[i]=0;
        st.insert(mp(kk[i],i));
    }
    ans.clear();
    while (st.size()>0)
    {
        if ((int)ans.size()==n) break;
        pair<int,int> p=*st.begin();
        st.erase(p);
        int l=p.ss;
        ans.pb(l);
        use[l]=1;
        vector<int> vv;
        for (int j=0; j<v[l].size(); j++)
            if (use[v[l][j].ff]==0)
            {
                int to=v[l][j].ff;
                st.erase(mp(kk[to],to));
                use[to]=1;
                vv.pb(to);
            }
        for (int jj=0; jj<vv.size(); jj++)
        {
            int l=vv[jj];
            for (int j=0; j<v[l].size(); j++)
            if (use[v[l][j].ff]==0)
            {
                int to=v[l][j].ff;
                st.erase(mp(kk[to],to));
                kk[to]--;
                st.insert(mp(kk[to],to));
            }
        }
    }
    if (ans.size()>=n)
    {
        cout<<"IndSet\n";
        for (int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        return;
    }
    ///cout<<"!!!!!!!!!"<<endl;
    cout<<"Impossible\n";

}
/**
2 5
1 2
3 1
1 4
5 1
1 6
**/
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}