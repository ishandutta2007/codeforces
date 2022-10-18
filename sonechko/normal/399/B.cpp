#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 11;
const int MOD = 998244353;

ll st[N];

int kol(string s)
{
    //cout<<s<<endl;
    int p=-1;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='B') {p=j; break;}
    if (p==-1) return 0;
    string t="";
    for (int j=s.size()-1; j>p; j--)
        t+=s[j];
    t+="R";
    for (int j=0; j<p; j++)
        t+="B";
    reverse(t.begin(),t.end());
    return kol(t)+1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    st[0]=1;
    for (int i=1; i<=60; i++)
        st[i]=st[i-1]*2ll;
    ll ans=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='B') ans+=st[j];
    cout<<ans<<"\n";
}
/**
B - 1
BB - 3
BBB - 7
BBBB - 15
BBBBB - 31

**/