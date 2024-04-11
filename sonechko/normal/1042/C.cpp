#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n;
    cin>>n;
    vector<pair<int,int> > v1,v2,v3;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l>0) v1.pb(mp(l,i)); else
        if (l==0) v2.pb(mp(l,i)); else
        v3.pb(mp(l,i));
    }
    sort(v1.begin(),v1.end());
    sort(v3.begin(),v3.end());
    if (v1.size()==0&&v3.size()==0)
    {
        for (int j=1; j<v2.size(); j++)
            cout<<1<<" "<<v2[j].ss<<" "<<v2[0].ss<<"\n";
        return 0;
    }
    if (v1.size()==0&&v3.size()==1)
    {
        for (int j=0; j<v2.size(); j++)
            cout<<1<<" "<<v2[j].ss<<" "<<v3[0].ss<<"\n";
        return 0;
    }
    if (v3.size()%2==1)
    {
        pair<int,int> p=v3.back();
        v2.pb(p);
        v3.pop_back();
    }
    for (int j=1; j<v2.size(); j++)
        cout<<1<<" "<<v2[j].ss<<" "<<v2[0].ss<<"\n";
    if (v2.size()>0) cout<<2<<" "<<v2[0].ss<<"\n";
    for (int j=0; j<v3.size(); j++)
        v1.pb(v3[j]);
    for (int j=1; j<v1.size(); j++)
        cout<<1<<" "<<v1[j].ss<<" "<<v1[0].ss<<"\n";
}