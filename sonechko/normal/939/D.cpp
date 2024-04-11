#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;

vector<int> v[N];
vector<int> p;
int use[N];

void rec(int l)
{
          p.pb(l);
          use[l]=1;
          for (int j=0; j<v[l].size(); j++)
          if (use[v[l][j]]==0) rec(v[l][j]);
}

int main()
{
         int n;
         cin>>n;
         string s,t;
         cin>>s>>t;
         for (int i=0; i<n; i++)
         {
                   if (s[i]!=t[i]) v[s[i]-'a'].pb(t[i]-'a');
                   if (s[i]!=t[i]) v[t[i]-'a'].pb(s[i]-'a');
         }
         vector<pair<char,char> > vv;
         for (int i=0; i<26; i++)
         if (use[i]==0) 
         {
                   rec(i);
                   for (int k=1; k<p.size(); k++)
                   vv.pb(mp(char(p[0]+'a'),char(p[k]+'a')));
                   p.clear();
         }
         cout<<vv.size()<<endl;
         for (int i=0; i<vv.size(); i++)
         cout<<vv[i].ff<<" "<<vv[i].ss<<endl;
}