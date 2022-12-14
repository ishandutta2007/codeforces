#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
bool vis[100][100];
int mx=0;
long long n,m;
void Try(int num)
{
    mx=max(mx,num);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (vis[i][j])continue;
            for (int ii=0;ii<n;ii++)
            {
                for (int jj=0;jj<m;jj++)
                {
                    if (abs(ii-i)+abs(jj-j)!=3)continue;
                    if (vis[ii][jj])continue;
                    vis[i][j]=1,vis[ii][jj]=1;
                    Try(num+2);
                    vis[i][j]=0,vis[ii][jj]=0;
                }
            }
        }
    }
}
int main()
{
    fast;
    //long long n,m;
    cin>>n>>m;
    if (n>m)swap(n,m);
    if (n==1)
    {
        cout<<6*(m/6)+max(m%6-3,0LL)*2<<endl;
    }
    else
    {
        if (n==2)
        {
            if (m==2)cout<<0<<endl;
            else if (m==3)cout<<4<<endl;
            else if (m==7)cout<<12<<endl;
            else
            {
                cout<<n*m<<endl;
            }
        }
        else
        {
            cout<<n*m-(n*m)%2<<endl;
        }
    }
}