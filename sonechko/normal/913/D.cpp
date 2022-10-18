#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long

const int N = 1e6 + 11;

vector<pair<int,int> > v[N];
int n;
long long T;

void rev(int l)
{
    set<pair<int,int> > st;
    for (int j=l; j<=n; j++)
    {
        for (int p=0; p<v[j].size(); p++)
            st.insert(v[j][p]);
    }
    vector<int> vv;
    for (int p=1; p<=l; p++)
    {
        pair<int,int> pp=*st.begin();
        st.erase(pp);
        vv.pb(pp.ss);
    }
    cout<<l<<endl;
    cout<<l<<endl;
    for (int i=0; i<l; i++)
        cout<<vv[i]<<" ";
    cout<<endl;
}

bool good(int l)
{
    set<pair<int,int> > st;
    for (int j=l; j<=n; j++)
    {
        for (int p=0; p<v[j].size(); p++)
            st.insert(v[j][p]);
    }
    if (st.size()<l) return false;
    long long sum=0;
    for (int p=1; p<=l; p++)
    {
        pair<int,int> pp=*st.begin();
        st.erase(pp);
        sum+=pp.ff;
    }
    if (sum<=T) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>T;
    for (int i=1; i<=n; i++)
    {
         int l,r;
         cin>>l>>r;
         v[l].pb(mp(r,i));
    }
    int l=1,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    if (good(r))
        rev(r); else
    if (good(l)) rev(l); else
    {
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<endl;
        return 0;
    }
}