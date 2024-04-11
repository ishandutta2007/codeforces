#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 5e5 + 11;

pair<int,int> a[N];
int b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    for (int i=1; i<=n; i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll t=0;
    for (int i=1; i<=n; i++)
        t+=1ll*(a[i].ff-b[i]);
    if (t!=0) {cout<<"NO"<<endl; return 0;}
    set<pair<int,int> > st1,st2;
    for (int i=1; i<=n; i++)
        if (a[i].ff<b[i]) st1.insert(mp(a[i].ff,i)); else
        if (a[i].ff>b[i]) st2.insert(mp(a[i].ff,i));
    vector<pair<int,pair<int, int> > > vv;

    while (st1.size()>0&&st2.size()>0)
    {
        pair<int,int> p1=*st1.rbegin();
        auto it=st2.lower_bound(mp(p1.ff+2,-1));
        if (it==st2.end()) {cout<<"NO\n"; return 0;}
        pair<int,int> p2=*it;
        ///cout<<p1.ff<<" "<<a[p1.ss].ss<<endl;
        ///cout<<p2.ff<<" "<<a[p2.ss].ss<<endl;
        st1.erase(p1);
        st2.erase(p2);
        if (p1.ff>=p2.ff) {cout<<"NO\n"; return 0;}
        int l=p1.ss,r=p2.ss;
        int c=min(b[l]-a[l].ff,a[r].ff-b[r]);
        c=min(c,(a[r].ff-a[l].ff)/2);
        ///cout<<c<<endl;
        if (c==0) {cout<<"NO\n"; return 0;}
        vv.pb(mp(a[l].ss,mp(a[r].ss,c)));
        a[l].ff+=c;
        a[r].ff-=c;
        if (a[l].ff!=b[l]) st1.insert(mp(a[l].ff,l));
        if (a[r].ff!=b[r]) st2.insert(mp(a[r].ff,r));
    }

    cout<<"YES\n";
    cout<<vv.size()<<"\n";
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j].ff<<" "<<vv[j].ss.ff<<" "<<vv[j].ss.ss<<"\n";
}
/**
2   2   6   7   14
4   5   5   8   9
+2  +3  -1  +1  -5

2  2  4  7  9
4  5  5  5  5
+2 +3 +1 -2 -4
**/