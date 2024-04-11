#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair

const int N = 5e5 + 11;

int kol[N],nx[N][27],all,nn[N];
map<string,bool> mt;

string a[N];

void update(string s, int num)
{
    if (mt[s]) return;
    mt[s]=1;
    a[num]=s;
    int ts=0;
    kol[ts]++;
    nn[ts]=num;
    for (int i=0; i<s.size(); i++)
    {
        int p=s[i]-'a';
        if (nx[ts][p]==0)
        {
            all++;
            nx[ts][p]=all;
        }
        ts=nx[ts][p];
        kol[ts]++;
        nn[ts]=num;
    }
}
int ans;
void find_(string s)
{
    if (s=="") return;
    int ts=nx[0][s[0]-'a'];
    if (ts==0) {ans+=s.size(); return;}
    for (int j=1; j<s.size(); j++)
    {
        int p=s[j]-'a';
        if (kol[ts]==0) {ans+=s.size(); return;}
        if (kol[ts]==1)
        {
            string c=a[nn[ts]];
            for (int j=0; j<c.size(); j++)
            if (s.size()==j||s[j]!=c[j]) {ans+=s.size(); return;}
            if (j+1+s.size()-c.size()<=s.size()) ans+=j+1+s.size()-c.size(); else
                ans+=s.size();
            return;
        }
        if (nx[ts][p]==0) {ans+=s.size(); return;}
        ts=nx[ts][p];
    }
    ans+=s.size();
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int ks=0;
    while(getline(cin,s))
    {
        string t="";
        s+=" ";
        for (int j=0; j<s.size(); j++)
            if (s[j]>='a'&&s[j]<='z') t+=s[j]; else
            {
                ans++;
                find_(t);
                ks++;
                update(t,ks);
                t="";
            }
    }
    cout<<ans<<endl;
}