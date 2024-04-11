#include <bits/stdc++.h>
using namespace std;
vector<int> G[1000000];
int group[1000000];
vector<pair<char,char> > ret;
void dsu(int x,int y)
{
    int u=group[x],v=group[y];
    if (u==v)return;
    ret.push_back({char('a'+x),char('a'+y)});
    for (auto x:G[u])
    {
        G[v].push_back(x);
        group[x]=v;
    }
}
int main ()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    for (int i=0;i<30;i++)G[i].push_back(i),group[i]=i;
    for (int i=0;i<n;i++)
        dsu(a[i]-'a',b[i]-'a');
    cout<<ret.size()<<endl;
    for (auto p:ret)cout<<p.first<<' '<<p.second<<endl;
}