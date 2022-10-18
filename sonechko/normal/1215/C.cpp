#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> v1,v2;
    for (int i=0; i<s.size(); i++)
        if (s[i]!=t[i])
    {
        if (s[i]=='a') v1.pb(i+1); else v2.pb(i+1);
    }
    vector<pair<int,int> > ans;
    while (v1.size()>1)
    {
        int l=v1.back();
        v1.pop_back();
        int r=v1.back();
        v1.pop_back();
        ans.pb(mp(l,r));
    }
    while (v2.size()>1)
    {
        int l=v2.back();
        v2.pop_back();
        int r=v2.back();
        v2.pop_back();
        ans.pb(mp(l,r));
    }
    if (v1.size()>0&&v2.size()>0)
    {
        int l=v1.back();
        v1.pop_back();
        int r=v2.back();
        v2.pop_back();
        ans.pb(mp(l,l));
        ans.pb(mp(l,r));
    }
    if (v1.size()>0||v2.size()>0) {cout<<-1; return 0;}
    cout<<ans.size()<<"\n";
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
}