#include<bits/stdc++.h>
using namespace std;
string rev[20];
map<string,int> mp;
int geti()
{
    string s;
    cin>>s;
    if(mp.count(s))
        return mp[s];
    else
    {
        int t=mp.size();
        rev[t]=s;
        return mp[s]=t;
    }
}
bool g[20][20];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        geti();
    for(int i=0;i<m;i++)
    {
        int a=geti();
        int b=geti();
        g[a][b]=true;
        g[b][a]=true;
    }
    m=(1<<n);
    int best=0;
    vector<string> bestv;
    for(int i=0;i<m;i++)
    {
        int t=i;
        vector<int> v;
        int c=0;
        while(t)
        {
            if(t%2)
                v.push_back(c);
            c++;
            t/=2;
        }
        bool ok=true;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<i;j++)
                if(g[v[i]][v[j]])
                {
                    ok=false;
                    break;
                }
            if(!ok)
                break;
        }
        if(ok && v.size()>best)
        {
            best=v.size();
            bestv.clear();
            for(int i=0;i<v.size();i++)
                bestv.push_back(rev[v[i]]);
        }
    }
    sort(bestv.begin(),bestv.end());
    cout<<best<<endl;
    for(int i=0;i<bestv.size();i++)
        cout<<bestv[i]<<'\n';
}