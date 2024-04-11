#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    set<pair<int,int> > st;
    for (int i=1; i<=n; i++)
    {
        int d=a[i];
        if (st.size()>0)
        {
            pair<int,int> p=*st.rbegin();
            if (p.ff==d) st.erase(p);
            while (st.size()>0)
            {
                pair<int,int> x=*st.rbegin();
                if (d<=x.ff+k) st.erase(x);
                else break;
            }
            if (p.ff==d) st.insert(mp(p.ff,p.ss+1));
            else st.insert(mp(d,1));
        } else st.insert(mp(d,1));
    }
    int ans=0;
    while (st.size()>0)
    {
        pair<int,int> p=*st.begin();
        st.erase(p);
        ans+=p.ss;
    }
    cout<<ans<<endl;
}