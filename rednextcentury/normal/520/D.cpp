#include<bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
map<pair<int,int>,int> mp;
int exists(pair<int,int> cube)
{
    return mp.count(cube);
}
void del(pair<int,int> cube)
{
    mp.erase(mp.find(cube));
}
int countDependencies(pair<int,int> cube)
{
    if (!exists(cube))return 0;
    return exists({cube.X-1,cube.Y-1})+exists({cube.X+1,cube.Y-1})+exists({cube.X,cube.Y-1});
}
vector<pair<int,int> > getDependencies(pair<int,int> cube)
{
    vector<pair<int,int> > ret;
    if (exists({cube.X-1,cube.Y-1}))ret.push_back({cube.X-1,cube.Y-1});
    if (exists({cube.X  ,cube.Y-1}))ret.push_back({cube.X  ,cube.Y-1});
    if (exists({cube.X+1,cube.Y-1}))ret.push_back({cube.X+1,cube.Y-1});
    return ret;
}
set<int> can;
void update(pair<int,int> cube)
{
    int ok=0;
    if (countDependencies({cube.X-1,cube.Y+1})==1)ok=1;
    if (countDependencies({cube.X  ,cube.Y+1})==1)ok=1;
    if (countDependencies({cube.X+1,cube.Y+1})==1)ok=1;
    int id = mp[cube];
    if (ok==1){
        if (can.count(id))can.erase(id);
    }
    else
        can.insert(id);
}
void updateDependencies(pair<int,int> cube)
{
    auto P = getDependencies(cube);
    for (auto x:P)update(x);
}
pair<int,int> a[1000000];
long long mod=1000000009;
long long ret=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].X>>a[i].Y;
        mp[a[i]]=i;
    }
    for (int i=0;i<n;i++)
        update(a[i]);
    for(int i=0;i<n;i++)
    {
        int id;
        if (i%2==0)
            id = *can.rbegin();
        else
            id = *can.begin();
        ret=(ret*n+id)%mod;
        can.erase(id);
        del(a[id]);
        pair<int,int> cube = a[id];
        if (exists({cube.X-1,cube.Y+1}))updateDependencies({cube.X-1,cube.Y+1});
        if (exists({cube.X  ,cube.Y+1}))updateDependencies({cube.X  ,cube.Y+1});
        if (exists({cube.X+1,cube.Y+1}))updateDependencies({cube.X+1,cube.Y+1});
        updateDependencies(a[id]);
    }
    cout<<ret<<endl;
}