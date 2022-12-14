//#include <cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
vector<pair<int,int> > v[1000000];
vector<int> h[1000000];
#define endl '\n'
struct point
{
    int x,y,id;
};
bool operator<(point a,point b)
{
    return a.id<b.id;
}
bool comp(point a,point b)
{
    if (a.x>=b.x && a.y>=b.y) return 0;
    else if (a.x<=b.x && a.y<=b.y) return 1;
    else
        return a.id<b.id;
}
point a[1000000],b[1000000];
int w[1000000];
bool vis[1000000];
int s[1000000];
vector<pair<int,int> > vec[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {

        cin>>a[i].x>>a[i].y,v[a[i].y-a[i].x+100000].push_back(make_pair(a[i].x,i));
    }
    for (int i=0;i<n;i++)
        cin>>w[i],h[w[i]+100000].push_back(i);
    for (int i=0;i<=200000;i++)
    {
        if (v[i].size()==0 && h[i].size()==0) continue;
        if (v[i].size()!=h[i].size())
        {
            cout<<"NO\n"<<endl;
            return 0;
        }
        sort(v[i].begin(),v[i].end());
        sort(h[i].begin(),h[i].end());
        for (int j=0;j<v[i].size();j++)
        {
            a[v[i][j].second].id=h[i][j];
        }
    }
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        b[i].id=a[i].id,b[i].x=a[i].x,b[i].y=a[i].y;
    }
    sort(b,b+n,comp);
    for (int i=0;i<n;i++)
    {
        if (b[i].x!=a[i].x || b[i].y!=a[i].y || b[i].id!=a[i].id)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<a[i].x<<" "<<a[i].y<<endl;
    }
}