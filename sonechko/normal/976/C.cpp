#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 3e5 + 11;

int b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,pair<int, int> > > vv;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        vv.pb(mp(l,mp(-r,i)));
        vv.pb(mp(r,mp(r,i)));
        b[i]=r;
    }
    sort(vv.begin(),vv.end());
    set<pair<int,int> > st;
    for (int i=0; i<vv.size(); i++)
    {
        if (vv[i].ss.ff<0)
        {
            if (st.size()>0)
            {
                pair<int,int> p=*st.rbegin();
                if (p.ff>=b[vv[i].ss.ss])
                {cout<<vv[i].ss.ss<<" "<<p.ss<<endl;
                exit(0);}
            }
            st.insert(mp(b[vv[i].ss.ss],vv[i].ss.ss));
        } else
        {
            st.erase(mp(b[vv[i].ss.ss],vv[i].ss.ss));
        }
    }
    cout<<"-1 -1"<<endl;
}