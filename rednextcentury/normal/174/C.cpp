#include <bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> num[1000000];
int cur[1000000];
vector<pair<int,int> > ret;
int a[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        num[a[i]].push_back(i);
    }
    s.insert(0);
    s.insert(n);
    for (int i=0;i<=100000;i++)
    {
        for (int j=0;j<num[i].size();j++)
        {
            int u=num[i][j];
            int l=*(--s.upper_bound(u));
            int r=*(s.upper_bound(u))-1;
            while(cur[l]<i)
            {
               ret.push_back(make_pair(l,r));
                cur[l]++;
            }
            s.insert(u);
            s.insert(u+1);
            cur[u+1]=cur[l];
        }
    }
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i].first+1<<' '<<ret[i].second+1<<endl;
}