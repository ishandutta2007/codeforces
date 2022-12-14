#include <bits/stdc++.h>
using namespace std;
int a[20][200][200];
vector<int> v[200][200];
bool has[200][200];
int main ()
{
    ios_base::sync_with_stdio(0);
    int n,q,c;
    cin>>n>>q>>c;
    for (int i=0;i<n;i++)
    {
        int x,y,s;
        cin>>x>>y>>s;
        a[0][x][y]+=s;
        v[x][y].push_back(s);
    }

    for (int i=1;i<=10;i++)
    {
        for (int x=1;x<=100;x++)
        {
            for (int y=1;y<=100;y++)
            {
                int ret = 0;
                for (int j=0;j<v[x][y].size();j++)
                    ret+=(v[x][y][j]+i)%(c+1);
                a[i][x][y]=ret;
            }
        }
    }
    for (int i=0;i<=10;i++)
    {
        for (int x=1;x<=100;x++)
        {
            for (int y=1;y<=100;y++)
            {
                a[i][x][y]+=a[i][x-1][y]+a[i][x][y-1]-a[i][x-1][y-1];
            }
        }
    }
    c++;
    for (int i=0;i<q;i++)
    {
        int t,x1,x2,y1,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        cout<<a[t%c][x2][y2]-a[t%c][x1-1][y2]-a[t%c][x2][y1-1]+a[t%c][x1-1][y1-1]<<endl;
    }
}