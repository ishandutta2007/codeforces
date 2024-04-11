#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
using namespace std;
int ret[1000000];
map<int,int> mp;
vector<pair<int,int> > e;
int main ()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int free=-1;
    queue<int> vec;
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if (max(a,b)!=n || a==b)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        ret[a]++;
        ret[b]++;
    }
    for (int i=n-1;i>=1;i--)
    {
        if (ret[i]==0)
        {
            if (vec.empty())
            {
                cout<<"NO"<<endl;
                return 0;
            }
            mp[vec.front()]=i;
            vec.pop();
        }
        else
        {
            int last = n;
            for (int j=1;j<ret[i];j++)
            {
                vec.push(free);

                e.push_back({last,free});
                last=free;
                free--;
            }
            e.push_back({last,i});
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<e.size();i++)
    {
        if (e[i].first<0)e[i].first=mp[e[i].first];
        if (e[i].second<0)e[i].second=mp[e[i].second];
        cout<<e[i].first<<' '<<e[i].second<<endl;
    }
}