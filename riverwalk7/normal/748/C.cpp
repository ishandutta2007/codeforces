#include <iostream>
#include <string>
#include <cmath>
#define MAXN 200010
using namespace std;
int x[MAXN];
int y[MAXN];
int N;
string a;
int z[MAXN];
bool vis[4];
int ans;
int main()
{
    cin>>N;
    cin>>a;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]=='U')
        {
            z[i]=0;
        }
        if(a[i]=='R')
        {
            z[i]=1;
        }
        if(a[i]=='D')
        {
            z[i]=2;
        }
        if(a[i]=='L')
        {
            z[i]=3;
        }
    }
    for(int i=0; i<a.length(); i++)
    {
        if(vis[(z[i]+2)%4]==true)
        {
            ans++;
            for(int j=0; j<4; j++)
            {
                vis[j]=false;
            }
        }
        vis[z[i]]=true;
    }
    ans++;
    cout<<ans<<endl;
}