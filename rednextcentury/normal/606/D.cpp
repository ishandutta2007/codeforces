#include <bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > z[1000000];
set<pair<int,int> > st;
map<int,int> adj[1000000];
queue<pair<int,int> > pos;
int ans[1000000][2];
vector<int> groups[1000000];
int group[1000000];
    int num=0;
int tot;
void add(int a,int b)
{
    int n=groups[a].size();
    int m=groups[b].size();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (num==tot)
                break;
            if (adj[groups[a][i]][groups[b][j]]) continue;
            num++;
            pos.push(make_pair(groups[a][i],groups[b][j]));
        }
        if (num==tot)
            break;
    }
    for (int i=0;i<n;i++)
    {
        groups[b].push_back(groups[a][i]);
        group[groups[a][i]]=b;
    }
    groups[a].clear();
}
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    tot=m+1;
    int h;
    for (int i=0;i<m;i++)
        cin>>z[i].first>>h,z[i].second.first=1-h,z[i].second.second=i;
    for (int i=1;i<=n;i++)
        st.insert(make_pair(1,i)),groups[i].push_back(i),group[i]=i;
    sort(z,z+m);
    for (int i=0;i<m;i++)
    {
        if (z[i].second.first==0)
        {
            if (st.size()<2)
            {
                cout<<-1<<endl;
                return 0;
            }
            set<pair<int,int> >::iterator it=--st.end();
            pair<int,int> a=*it,b=*(--it);
            st.erase(it);
            st.erase(--st.end());
            adj[groups[a.second][0]][groups[b.second][0]]=1;
            adj[groups[b.second][0]][groups[a.second][0]]=1;
            ans[z[i].second.second][0]=groups[a.second][0];
            ans[z[i].second.second][1]=groups[b.second][0];
            if (groups[a.second].size()<groups[b.second].size())
                add(a.second,b.second),a.first=a.first+b.first,a.second=b.second;
            else
                add(b.second,a.second),a.first=a.first+b.first;
            st.insert(a);
        }
        else
        {
            if (pos.empty())
            {
                cout<<-1<<endl;
                return 0;
            }
            pair<int,int> a=pos.front();
            pos.pop();
            ans[z[i].second.second][0]=a.first;

            ans[z[i].second.second][1]=a.second;

        }
    }
    for (int i=0;i<m;i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}