#include<bits/stdc++.h>
using namespace std;
long long v[1000000],d[1000000],p[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>v[i]>>d[i]>>p[i];
    }
    queue<int> q;
    vector<int> ret;
    int cur=0;
    for (int j=0;j<n;j++)
    {
        while(!q.empty())
        {
            int y=q.front();
            q.pop();
            for (int i=y+1;i<n;i++)
            {
                p[i]-=d[y];
                if (p[i]<0 && p[i]+d[y]>=0)
                    q.push(i);
            }
        }
        if (p[j]<0)
            continue;
        cur++;
        ret.push_back(j+1);
        int h=v[j];
        for (int i=j+1;i<n;i++)
        {
            if (p[i]<0)
                continue;
            p[i]-=h;
            if (p[i]<0 && p[i]+h>=0)
                    q.push(i);
            h--;
            if (h<0)
                break;
        }
    }
    cout<<cur<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}