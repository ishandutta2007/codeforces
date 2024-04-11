#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k;
    cin>>k;
    int kk=0;
    vector<pair<char,bool> > v;
    for (int j=0; j<s.size(); j++)
        if (s[j]>='a'&&s[j]<='z')
        {
            if (j<s.size()&&s[j+1]=='?')
            {
                v.pb(mp(s[j],0));
            } else
            if (j<s.size()&&s[j+1]=='*')
            {
                for (int t=1; t<=200; t++)
                    v.pb(mp(s[j],0));
            } else
            {
                kk++;
                v.pb(mp(s[j],1));
            }
        }
    if (kk>k||v.size()<k) {cout<<"Impossible"; return 0;}
    for (int j=0; j<v.size(); j++)
        if (v[j].ss==1) cout<<v[j].ff; else
        if (kk<k)
    {
        kk++;
        cout<<v[j].ff;
    }
}