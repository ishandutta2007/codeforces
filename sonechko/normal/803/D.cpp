#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define int long long
#define ll long long
#define sqr(a) ((a)*(a))
#define ld long double
const int N = 1e6 + 11;
string s[N];
int n,sz;
bool good(int k)
{
    int ps=0,kol=1;
    for (int i=1; i<=sz; i++)
    if (s[i].size()<=k-ps) {ps+=s[i].size();} else
    if (s[i].size()>k) return false; else
    {
        kol++;
        ps=s[i].size();
    }
    if (kol<=n) return true; else return false;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    string t;
    sz=0;
    while (cin>>t)
    {
        string d="";
        for (int i=0; i<t.size(); i++)
        {
            d+=t[i];
            if (t[i]=='-') {sz++; s[sz]=d; d="";}
        }
        sz++;
        s[sz]=d;
    }
    for (int i=1; i<sz; i++)
        {
            string t=s[i];
            if (t[t.size()-1]!='-') t+=" ";
            s[i]=t;
        }
    int l=1,r=1000000;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<endl; else cout<<r<<endl;
}