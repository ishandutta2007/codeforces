#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;
const ll MOD = 1e9 + 7;

bool can_do(string s, int pos)
{
    if (s[pos-6]!='a'&&s[pos-6]!='?') return 0;
    if (s[pos-5]!='b'&&s[pos-5]!='?') return 0;
    if (s[pos-4]!='a'&&s[pos-4]!='?') return 0;
    if (s[pos-3]!='c'&&s[pos-3]!='?') return 0;
    if (s[pos-2]!='a'&&s[pos-2]!='?') return 0;
    if (s[pos-1]!='b'&&s[pos-1]!='?') return 0;
    if (s[pos]!='a'&&s[pos-0]!='?') return 0;
    return 1;
}

void up()
{
    int nn;
    cin>>nn;
    string s;
    cin>>s;
    s="."+s;
    int kol=0;
    for (int pos=7; pos<s.size(); pos++)
        if (can_do(s,pos))
    {
        string t=s;
        t[pos-6]='a';
        t[pos-5]='b';
        t[pos-4]='a';
        t[pos-3]='c';
        t[pos-2]='a';
        t[pos-1]='b';
        t[pos]='a';
        for (int j=1; j<s.size(); j++)
            if (t[j]=='?') t[j]='z';
        int c=1;
        for (int j=7; j<s.size(); j++)
        if (j!=pos&&can_do(t,j)==1) c=0;
        if (c==1)
        {
            cout<<"Yes\n";
            for (int j=1; j<t.size(); j++)
                cout<<t[j];
            cout<<"\n";
            return;
        }
    }
    cout<<"No\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}