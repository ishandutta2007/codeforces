#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;


vector<int> use[N];
vector<int> v[N];
int res[N];


int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
              int p=s[i]-'a';
              v[p].pb(i);
    }
    int kol1=0;
    for (int j=0; j<26; j++)
    {
              vector<string> vv;
              for (int d=0; d<v[j].size(); d++)
              {
                        int x=v[j][d];
                        string g="";
                        for (int j=x; j<s.size(); j++)
                        g+=s[j];
                        for (int j=0; j<x; j++)
                        g+=s[j];
                        vv.pb(g);
              }
              int kols=0;
              for (int x=0; x<s.size(); x++)
              {
                        for (int j=0; j<=26; j++)
                        use[j].clear();
                        for (int j=0; j<vv.size(); j++)
                        use[vv[j][x]-'a'].pb(j);
                        int ksks=0;
                        for (int j=0; j<=26; j++)
                        if (use[j].size()==1) ksks++;
                        kols=max(kols,ksks);
              }
              kol1+=kols;
    }
    cout.precision(10);
    cout<<fixed;
    cout<<(long double)kol1/(long double)s.size()<<endl;
}