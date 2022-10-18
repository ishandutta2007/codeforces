#include<bits/stdc++.h>
using namespace std;
const int N = 500000 + 11;
#define ll long long
#define ss second
#define ff first
#define ld long double
#define pb push_back
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string st;
    cin>>st;
    for (int i=0; i<st.size(); i++)
        use[st[i]-'a']++;
    string s;
    cin>>s;
    string p1="",p2="";
    int k=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='*') k=1; else
        if (k==0) p1+=s[i]; else p2+=s[i];
    int n;
    cin>>n;
    for (int ii=1; ii<=n; ii++)
    {
        string t;
        cin>>t;
        int ans=1;
        if (t.size()<p1.size()+p2.size()) ans=-1; else
        if (t.size()>p1.size()+p2.size()&&k==0) ans=-1; else
        {
            for (int i=0; i<p1.size(); i++)
                if (p1[i]=='?')
            {
                if (use[t[i]-'a']==0) ans=-1;
            } else
            if (t[i]!=p1[i]) ans=-1;
            int c=t.size()-p1.size()-p2.size();
            for (int i=p1.size(); i<p1.size()+c; i++)
            if (use[t[i]-'a']==1) ans=-1;
            for (int i=p1.size()+c; i<t.size(); i++)
            if (p2[i-p1.size()-c]=='?')
            {
                if (use[t[i]-'a']==0) ans=-1;
            } else
            if (t[i]!=p2[i-p1.size()-c]) ans=-1;
        }
        if (ans==1) cout<<"YES"<<"\n"; else cout<<"NO\n";
    }
}