#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> v1[N],v2[N];
int l1[N],r1[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        v1[l].pb(i);
        v2[r].pb(i);
        l1[i]=l;
        r1[i]=r;
    }
    int kk=0;
    set<pair<int,int> > st;
    for (int i=1; i<=200000; i++)
    {
        for (int j=0; j<v1[i].size(); j++)
            st.insert(mp(r1[v1[i][j]],v1[i][j]));
        while (st.size()>k)
        {
            pair<int,int> p=*st.rbegin();
            st.erase(p);
            use[p.ss]=1;
            kk++;
        }
        for (int j=0; j<v2[i].size(); j++)
            st.erase(mp(i,v2[i][j]));
    }
    cout<<kk<<"\n";
    for (int i=1; i<=n; i++)
        if (use[i]) cout<<i<<" ";
}