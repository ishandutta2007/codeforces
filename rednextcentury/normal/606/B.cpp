#include <bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    string s;
    cin>>s;
    int k=s.length();
    int tot=n*m;
    cout<<1;
    tot--;
    for (int i=0;i<k-1;i++)
    {
        vis[x][y]=1;
        int xx=x,yy=y;
        if (s[i]=='U')
            xx--;
        else if (s[i]=='D')
            xx++;
        else if (s[i]=='L')
            yy--;
        else
            yy++;
        if (xx>=1 && yy>=1 && xx<=n && yy<=m)
        {
            x=xx,y=yy;
            if (!vis[xx][yy])
                cout<<" "<<1,tot--;
            else
                cout<<" "<<0;
        }
        else
            cout<<" 0";
    }
    cout<< " "<<tot<<endl;
}