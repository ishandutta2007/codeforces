#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[10];
vector<pair<int,int> > ret;
map<pair<int,int> ,int> mp;
void solve(pair<int,int> p1,pair<int,int> p2,pair<int,int>  p3)
{
    pair<int,int> f;
    f.first= p1.first+p3.first-p2.first;
    f.second = p1.second+p3.second - p2.second;
    if (++mp[f]==1)
        ret.push_back(f);
}
int main()
{
    for (int i=0;i<3;i++)
        cin>>p[i].first>>p[i].second;
    int a[]={1,2,3};
    do
    {
        solve(p[a[0]-1],p[a[1]-1],p[a[2]-1]);
    }while(next_permutation(a,a+3));
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i].first<<' '<<ret[i].second<<endl;
}