#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int kol[N];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    string t;
    cin>>t;
    for (int p=0; p<s.size(); p++)
        kol[s[p]-'0']++;
    if (s.size()<t.size())
    {
        for (int p=9; p>=0; p--)
        for (int d=kol[p]; d>=1; d--)
        cout<<p;
        cout<<endl;
        return 0;
    }
    string ans="";
    for (int x=(t[0]-'0')-1; x>=0; x--)
        if (kol[x]>0)
    {
        kol[x]--;
        ans+=char(x+'0');
        for (int pp=9; pp>=0; pp--)
        for (int d=kol[pp]; d>=1; d--)
        ans+=char(pp+'0');
        kol[x]++;
        break;
    }
    int uu=0;
    for (int p=1; p<t.size(); p++)
    {
        if (kol[t[p-1]-'0']==0) {uu=1; break;}
        kol[t[p-1]-'0']--;
        string res="";
        for (int j=0; j<p; j++)
            res+=t[j];
        for (int x=(t[p]-'0')-1; x>=0; x--)
        if (kol[x]>0)
        {
            kol[x]--;
            res+=char(x+'0');
            for (int pp=9; pp>=0; pp--)
            for (int d=kol[pp]; d>=1; d--)
            res+=char(pp+'0');
            kol[x]++;
            break;
        }
        if (res.size()==t.size()) ans=res;
    }
    if (uu==0&&kol[t[t.size()-1]-'0'])
    {
        cout<<t<<endl;
        return 0;
    }
    cout<<ans<<endl;
}