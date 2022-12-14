#include <bits/stdc++.h>
using namespace std;
long long a[1000002];
vector<int> vec[1000002];
vector<int> H;
vector<int> L;
#define SQRT 300
int t[1000002];
int inter[100003][401];
bool has[100003][401];
long long ans[1000000];
long long add[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int num=1;
    for (int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        if (k>SQRT)
            H.push_back(i),t[i]=num,num++;
        else
            L.push_back(i);
        while(k--)
        {
            int x;
            cin>>x;
            vec[i].push_back(x);
        }
    }
    for (int i=0;i<H.size();i++)
        for (int j=0;j<vec[H[i]].size();j++)
            has[vec[H[i]][j]][i]=1,ans[i]+=a[vec[H[i]][j]];
    for (int i=0;i<m;i++)
        for (int j=0;j<vec[i].size();j++)
            for (int x=0;x<H.size();x++)
                if (has[vec[i][j]][x])
                    inter[i][x]++;
    while(q--)
    {
        char typ;
        cin>>typ;
        if (typ=='?')
        {
            int x;
            cin>>x;
            x--;
            long long ret=0;
            if (t[x])
            {
                ret=ans[t[x]-1];

                for (int i=0;i<H.size();i++)
                    if (i!=(t[x]-1))
                        ret+=inter[x][i]*add[i];
            }
            else
            {
                for (int i=0;i<vec[x].size();i++)
                    ret+=a[vec[x][i]];
                for (int i=0;i<H.size();i++)
                    ret+=inter[x][i]*add[i];
            }
            cout<<ret<<endl;
        }
        else
        {
            int x;
            long long val;
            cin>>x>>val;
            x--;
            if (t[x])
            {
                ans[t[x]-1]+=val*vec[x].size();
                add[t[x]-1]+=val;
            }
            else
            {
                for (int i=0;i<vec[x].size();i++)
                    a[vec[x][i]]+=val;
                for (int i=0;i<H.size();i++)
                    ans[i]+=inter[x][i]*val;
            }
        }
    }
}