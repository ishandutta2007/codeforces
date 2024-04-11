#include<bits/stdc++.h>
using namespace std;

#define y1 ojf
#define ld long double
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int N = 3e5 + 11;

int a[N],f[N],s[N];
vector<int> v1[N],v2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    int pos=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]!=0)
        {
            if (f[a[i]]==0) {f[a[i]]=i;}
            s[a[i]]=i;
        } else pos=i;
    }
    vector<int> d;
    v1[1].pb(1);
    v2[n].pb(1);
    for (int i=2; i<=q; i++)
        if (f[i]==0&&pos!=0) {v1[pos].pb(i); v2[pos].pb(i); a[pos]=i;} else
        if (f[i]==0&&pos==0) d.pb(i); else
    {
        int l=f[i];
        int r=s[i];
        v1[l].pb(i);
        v2[r].pb(i);
        d.clear();
    }
    if (d.size()>0) {cout<<"NO"<<endl; return 0;}
    set<int> st;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<v1[i].size(); j++)
            st.insert(v1[i][j]);
        int c=a[i];
        a[i]=*st.rbegin();
        if (c!=0&&a[i]!=c) {cout<<"NO"<<endl; return 0;}
        for (int j=0; j<v2[i].size(); j++)
            st.erase(v2[i][j]);
    }
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}