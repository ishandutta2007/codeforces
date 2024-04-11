#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
vector<int> row[MAXN];
vector<int> col[MAXN];
ll ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        row[x].push_back(y); col[y].push_back(x);
    }
    for(int i=1;i<=100000;i++) sort(row[i].begin(),row[i].end());
    for(int i=1;i<=100000;i++) sort(col[i].begin(),col[i].end());
    ans=1;
    int lb=1,ub=2,rb=m,db=n,x=1,y=1;
    do
    {
        int to=rb;
        for(int i=0;i<(int)row[x].size();i++)
        {
            if(row[x][i]>y&&row[x][i]-1<rb)
            {
                to=row[x][i]-1;
                break;
            }
        }
        if(to<=y&&(!(x==1&&y==1))) break;
        ans+=to-y; y=to; rb=to-1;
        to=db;
        for(int i=0;i<(int)col[y].size();i++)
        {
            if(col[y][i]>x&&col[y][i]-1<db)
            {
                to=col[y][i]-1;
                break;
            }
        }
        if(to<=x) break;
        ans+=to-x; x=to; db=to-1;
        to=lb;
        for(int i=(int)row[x].size()-1;i>=0;i--)
        {
            if(row[x][i]<y&&row[x][i]+1>lb)
            {
                to=row[x][i]+1;
                break;
            }
        }
        if(to>=y) break;
        ans+=y-to; y=to; lb=to+1;
        to=ub;
        for(int i=(int)col[y].size()-1;i>=0;i--)
        {
            if(col[y][i]<x&&col[y][i]+1>ub)
            {
                to=col[y][i]+1;
                break;
            }
        }
        if(to>=x) break;
        ans+=x-to; x=to; ub=to+1;
    }while(true);
    if(ans+k==1LL*n*m) puts("Yes"); else puts("No");
    return 0;
}