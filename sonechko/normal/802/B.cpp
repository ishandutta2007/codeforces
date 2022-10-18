#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 4e5 + 11;
int a[N],use[N],las[N],nex[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (las[a[i]]!=0) nex[las[a[i]]]=i;
        las[a[i]]=i;
    }
    int ans=0;
    set<pair<int,int> > st;
    for (int i=1; i<=n; i++)
    {
        int k=a[i];
        if (use[k]==0)
        {
            ans++;
            int kol=st.size();
            if (kol==m)
            {
                pair<int,int> p=*st.rbegin();
                st.erase(p);
                use[p.ss]=0;
            }
        } else st.erase(mp(use[k],k));
        use[k]=nex[i];
        if (use[k]!=0) st.insert(mp(use[k],k));
    }
    cout<<ans<<endl;
}