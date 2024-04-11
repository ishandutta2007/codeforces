#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int a[N],b[N];
#define pb push_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    int kol=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='?') kol++; else a[s[i]-'a'+1]++;
    }
    for (int i=0; i<t.size(); i++)
    b[t[i]-'a'+1]++;
    int ans=0;
    vector<int> v;
    for (int ii=1; ii<=1000000; ii++)
    {
        int kk=0;
        for (int i=1; i<=26; i++)
        if (a[i]<b[i]) kk+=b[i]-a[i];
        if (kk>kol) break;
        kol-=kk;
        ans++;
        for (int i=1; i<=26; i++)
        if (a[i]<b[i])
        {
            for (int j=1; j<=b[i]-a[i]; j++)
                v.pb(i);
            a[i]=0;
        }
        else a[i]-=b[i];
    }
    for (int i=0; i<s.size(); i++)
    if (s[i]=='?')
    {
        if (v.size()==0) cout<<"a"; else
           {
           cout<<char(v.back()-1+'a');
           v.pop_back();
           }
    } else cout<<s[i];
}