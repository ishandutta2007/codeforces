#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long adj[100][100];
pair<long long,long long> V[1000];
bool vis[100];
long long n;
long long num[100];
string pos="UDLR";
void draw(char dir,long long v,long long x,long long y,long long len)
{
    V[v]=make_pair(x,y);
    vis[v]=1;
    int c=0;
    for (long long i=1;i<=n;i++)
    {
        if (vis[i])continue;
        if (!adj[v][i])continue;
        if (pos[c]==dir)
            c++;
        if (pos[c]=='U')
        {
            draw('D',i,x,y+(1LL<<len),len-2);
            c++;
        }
        else if (pos[c]=='D')
        {
            draw('U',i,x,y-(1LL<<len),len-2);
            c++;
        }
        else if (pos[c]=='L')
        {
            draw('R',i,x-(1LL<<len),y,len-2);
            c++;
        }
        else if (pos[c]=='R')
        {
            draw('L',i,x+(1LL<<len),y,len-2);
            c++;
        }
    }
}
int main()
{
    fast
    cin>>n;
    for (long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x][y]=adj[y][x]=1;
        num[x]++,num[y]++;
    }
    long long mx=-1,nn=1;
    for (long long i=1;i<=n;i++)
    {
        if (num[i]>mx)
            mx=num[i],nn=1;
        else if (num[i]==mx)
            nn++;
    }
    if (mx>4)
        cout<<"NO"<<endl;
    else{
            cout<<"YES"<<endl;
        draw('N',1,0,0,58);

    for (long long i=1;i<=n;i++)
        cout<<V[i].first<<' '<<V[i].second<<endl;
    }
}