#include<iostream>
#include<map>

using namespace std;

map<long long,long long> Map;

int main ()
{
    long long n,m,i,x,y,res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        Map[x]=y;
    }

    cin>>m;

    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        Map[x]=max(Map[x],y);
    }


    map<long long,long long> :: iterator it;

    for(it=Map.begin();it!=Map.end();it++)
        res+=it->second;

    cout<<res<<"\n";

    return 0;
}