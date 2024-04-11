#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
using namespace std;
set<pair<int,int> > s;
pair<int,int> a[1000000];
int ret[1000000];
int main ()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    int D=1;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        if (s.empty() || a[i].first-(*s.begin()).first<=d)
        {
            ret[a[i].second]=D;
            s.insert({a[i].first,D++});
        }
        else
        {
            pair<int,int> p=*s.begin();
            s.erase(s.begin());
            ret[a[i].second]=p.second;
            s.insert({a[i].first,p.second});
        }
    }
    cout<<D-1<<endl;
    for (int i=0;i<n;i++)
        cout<<ret[i]<<' ';
}