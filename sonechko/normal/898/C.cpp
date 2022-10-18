#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
vector<string> vv;
vector<pair<int,string> > a[1000];
bool good(string s, string t)
{
    if (s.size()<t.size()) return false;
    int j=s.size()-1;
    for (int p=t.size()-1; p>=0; p--)
    {
        if (t[p]!=s[j]) return false;

        j--;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int ks=-1;
        for (int j=0; j<vv.size(); j++)
        if (vv[j]==s) {ks=j; break;}
        if (ks==-1) {vv.pb(s); ks=vv.size()-1;}
        int kol;
        cin>>kol;
        for (int j=1; j<=kol; j++)
        {
            string s;
            cin>>s;
            a[ks].pb(mp(s.size(),s));
        }
    }
    cout<<vv.size()<<endl;
    for (int j=0; j<vv.size(); j++)
    {
        vector<string> p;
        sort(a[j].begin(),a[j].end());
        for (int d=a[j].size()-1; d>=0; d--)
        {
            int kol=0;
            for (int x=0; x<p.size(); x++)
                if (good(p[x],a[j][d].ss)) kol=1;
            if (kol==0) p.pb(a[j][d].ss);
        }
        cout<<vv[j]<<" "<<p.size()<<" ";
        for (int i=0; i<p.size(); i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
}