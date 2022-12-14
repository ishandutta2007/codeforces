#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string st[1000000];
pair<string,string> getStuff(string s)
{
    string A="",B="";
    int num=0;
    for (auto x:s)
    {
        if (x=='/')num++;
        if (num>2)B+=x;
        else A+=x;
    }
    B+="-";
    return {A,B};
}
pair<long long,long long> Hash(string s)
{
    long long h1=0;
    long long h2=0;
    long long seed1=1337,mod=1000000009;
    long long seed2=1007;
    for (auto x:s)
    {
        h1=(h1*seed1+x)%mod;
        h2=h2*seed2+x;
    }
    return {h1,h2};
}
pair<pair<long long,long long>,int> a[1000000];
vector<string> vec[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int tot=0;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        pair<string,string> stuff = getStuff(s);
        int cur;
        if (mp.find(stuff.first)==mp.end())
            mp[stuff.first]=tot++;
        cur = mp[stuff.first];
        vec[cur].push_back(stuff.second);
        st[cur]=stuff.first;
        //cout<<stuff.first<<' '<<stuff.second<<endl;
    }
    for (int i=0;i<tot;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        string cur="";
        string last="";
        for (auto x:vec[i]){
            if (x!=last)
                cur+=x;
            last=x;
        }
        a[i].first = Hash(cur);
        a[i].second=i;
    }
    sort(a,a+tot);
    vector<vector<int> > ret;
    vector<int> cur;
    cur.push_back(a[0].second);
    for (int i=1;i<tot;i++)
    {
        if (a[i].first!=a[i-1].first)
        {
            if (cur.size()>1)ret.push_back(cur);
            cur.clear();cur.push_back(a[i].second);
        }
        else
            cur.push_back(a[i].second);
    }
    if (cur.size()>1)ret.push_back(cur);
    cout<<ret.size()<<endl;
    for (auto v:ret)
    {
        for (int i=0;i<v.size();i++)
        {
            cout<<st[v[i]];
            if (i+1<v.size())cout<<' ';
            else cout<<"\n";
        }
    }
}