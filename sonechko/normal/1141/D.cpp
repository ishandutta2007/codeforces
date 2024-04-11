#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;

vector<int> kol1[N],kol2[N];
vector<int> t1,t2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='?') t1.pb(i+1); else kol1[s[i]-'a'].pb(i+1);
    for (int i=0; i<t.size(); i++)
        if (t[i]=='?') t2.pb(i+1); else kol2[t[i]-'a'].pb(i+1);
    vector<pair<int,int> > vv;
    for (int i=0; i<26; i++)
    {
        while (kol1[i].size()>0&&kol2[i].size()>0)
        {
            vv.pb(mp(kol1[i].back(),kol2[i].back()));
            kol1[i].pop_back();
            kol2[i].pop_back();
        }
        while (kol1[i].size()>0&&t2.size()>0)
        {
            vv.pb(mp(kol1[i].back(),t2.back()));
            kol1[i].pop_back();
            t2.pop_back();
        }
        while (t1.size()>0&&kol2[i].size()>0)
        {
            vv.pb(mp(t1.back(),kol2[i].back()));
            t1.pop_back();
            kol2[i].pop_back();
        }
    }
    while (t1.size()>0&&t2.size()>0)
    {
        vv.pb(mp(t1.back(),t2.back()));
        t1.pop_back();
        t2.pop_back();
    }
    cout<<vv.size()<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j].ff<<" "<<vv[j].ss<<"\n";
}