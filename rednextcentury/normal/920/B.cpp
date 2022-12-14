#include <bits/stdc++.h>
using namespace std;
queue<int> q;
pair<int,int > t[100000];
int r[1000000];
int l[1000000];
int ret[1000000];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        while(!q.empty())q.pop();
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>l[i]>>r[i];
            t[i]=make_pair(l[i],i);
        }
        sort(t,t+n);
        for (int i=0;i<n;i++)
            q.push(t[i].second);
        int tim=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if (tim>r[x])
            {
                ret[x]=0;
                continue;
            }
            tim=max(tim,l[x]);
            ret[x]=tim;
            tim++;
        }
        for (int i=0;i<n;i++)
            cout<<ret[i]<<' ';
        cout<<endl;
    }
}