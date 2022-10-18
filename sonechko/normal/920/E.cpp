#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 3e5 + 11;

map<pair<int,int>,bool> mt;

set<int> st;
int kol[N],use[N];
vector<int> dd;

void bfs(int l)
{
    st.erase(l);
    set<int> stt=st;
    vector<int> vv;
    vv.pb(l);
    use[l]=1;
    for (int i=0; i<vv.size(); i++)
    {
        int l=vv[i];
        set<int> ps=stt;
        while (ps.size()>0)
        {
            int g=*ps.begin();
            ps.erase(g);
            if (mt[mp(g,l)]==0)
                {use[g]=1; stt.erase(g); st.erase(g); vv.pb(g);}
        }
    }
    dd.pb(vv.size());
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        mt[mp(l,r)]=1;
        mt[mp(r,l)]=1;
    }
    for (int i=1; i<=n; i++)
        st.insert(i);
    for (int i=1; i<=n; i++)
        if (use[i]==0) bfs(i);
    sort(dd.begin(),dd.end());
    cout<<dd.size()<<endl;
    for (int i=0; i<dd.size(); i++)
        cout<<dd[i]<<" ";
    cout<<endl;
}