#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000];
vector<pair<int,int> > vec;
bool vis[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        int num=0;
        for (int i=0;i<n;i++)
        {
            if (a[i].second==v)
                num=a[i].first,a[i].first=-100000;
        }
        sort(a,a+n);
        reverse(a,a+n);
        for (int i=0;i<min(num,n);i++)
        {
            if (a[i].second!=v && !vis[a[i].second])
            {
                vec.push_back(make_pair(v,a[i].second));
                vis[a[i].second]=1;
                q.push(a[i].second);
            }
            else num++;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (!vis[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)
        cout<<vec[i].first+1<<' '<<vec[i].second+1<<endl;
}