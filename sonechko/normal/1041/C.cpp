#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 11;

pair<int,int> a[N];
int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    set<pair<int,int> > st;
    int kol=1;
    st.insert(mp(-1000000000,1));
    for (int i=1; i<=n; i++)
    {
        int l=a[i].ff;
        pair<int,int> p=*st.begin();
        if (l-p.ff>d) {res[a[i].ss]=p.ss; st.erase(p); st.insert(mp(l,p.ss));}
        else {kol++; res[a[i].ss]=kol; st.insert(mp(l,kol));}
    }
    cout<<kol<<endl;
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}