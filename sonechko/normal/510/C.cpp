#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e3;


int use[N],used[N];
vector<int> v[N];
string ans,p;


void dfs(int l)
{
    use[l]=1;
    for (int i=0; i<v[l].size(); i++)
    {
        int to=v[l][i];
        if (use[to]==1) {cout<<"Impossible"<<endl; exit(0);}
        if (use[to]==0) dfs(to);
    }
    char ch=l+'a';
    string d="";
    d+=ch;
    p=d+p;
    use[l]=2;
}


int main()
{
    int n;
    cin>>n;
    string t;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        if (i!=1)
        {
            for (int k=0; k<t.size(); k++)
            if (k>=s.size()) {cout<<"Impossible"<<endl; return 0;} else
            if (s[k]!=t[k]) {v[t[k]-'a'].pb(s[k]-'a'); used[s[k]-'a']=1; break;}
        }
        t=s;
    }
    for (int i=0; i<26; i++)
        if (used[i]==0) {dfs(i); ans=p+ans; p="";}
    if (ans.size()!=26) {cout<<"Impossible"<<endl; return 0;}
    cout<<ans<<endl;
}