
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 70000 + 11;
map<string,int> mt;
string a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int ii=1; ii<=n; ii++)
    {
        string s;
        cin>>s;
        a[ii]=s;
        for (int i=0; i<s.size(); i++)
        {
            string p="";
            for (int j=i; j<s.size(); j++)
            {
                p+=s[j];
                mt[p]++;
            }
        }
    }
    for (int ii=1; ii<=n; ii++)
    {
        string s=a[ii];
        vector<string> v;
        for (int i=0; i<s.size(); i++)
        {
            string p="";
            for (int j=i; j<s.size(); j++)
            {
                p+=s[j];
                v.pb(p);
            }
        }
        sort(v.begin(),v.end());
        v.pb("-");
        string ans=s;
        int kol=0;
        for (int i=0; i<v.size()-1; i++)
        {
            kol++;
            if (v[i]!=v[i+1])
            {
                if (mt[v[i]]==kol) {if (v[i].size()<ans.size())
                    ans=v[i];}
                kol=0;
            }
        }
        cout<<ans<<"\n";
    }
}