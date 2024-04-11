#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
long long fact[20];
long long a[50];
vector<pair<long long,int> > vec;
vector<long long> cur;
void Try(int id,long long sum,int num)
{
    if (id==cur.size())
    {
        vec.push_back({sum,num});
    }
    else
    {
        Try(id+1,sum,num);
        Try(id+1,sum+cur[id],num);
        if (cur[id]<=18)
            Try(id+1,sum+fact[cur[id]],num+1);
    }
}
map<pair<long long,int> , int> mp;
int main()
{
    fact[0]=1;
    for (int i=1;i<=18;i++)
        fact[i]=i*fact[i-1];
    int n,k;
    long long S;
    cin>>n>>k>>S;
    for (int i=0;i<n;i++)cin>>a[i];
    int m=n/2;
    for (int i=0;i<m;i++)
        cur.push_back(a[i]);
    Try(0,0,0);
    for (auto x:vec)
        mp[x]++;
    vec.clear(),cur.clear();
    for(int i=m;i<n;i++)
        cur.push_back(a[i]);
    Try(0,0,0);
    long long ret=0;
    for (auto x:vec)
    {
        if (x.first>S)continue;
        for (int j=0;j<=k-x.second;j++)
            if (mp.find({S-x.first,j})!=mp.end())
                ret+=mp[{S-x.first,j}];
    }
    cout<<ret<<endl;
}