#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mp make_pair
#define ll long long
bool vis[1000000];
int p[1000000];
vector<long long> vec;
int main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>p[i];
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            int sz=0;
            int v=i;
            while(!vis[v])
            {
                sz++;
                vis[v]=1;
                v=p[v];
            }
            vec.push_back(sz);
        }
    }
    sort(vec.begin(),vec.end());
    if (vec.size()>1)
    {
        long long x=vec[vec.size()-1];
        long long y=vec[vec.size()-2];
        vec.pop_back();
        vec.pop_back();
        vec.push_back(x+y);
    }
    long long ret=0;
    for (int i=0;i<vec.size();i++)
        ret+=(vec[i])*(vec[i]);
    cout<<ret<<endl;
}