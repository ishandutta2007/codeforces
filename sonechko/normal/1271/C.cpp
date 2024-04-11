#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int n,sx,sy;
int a[N],b[N];
int ans,xx,yy;

int dist(int x, int y, int xx, int yy)
{
    return abs(x-xx)+abs(y-yy);
}

void up(int x, int y)
{
    if (x<0||y<0) return;
    if (x>1000000000||y>1000000000) return;
    int kk=0;
    for (int i=1; i<=n; i++)
        if (dist(sx,sy,x,y)+dist(x,y,a[i],b[i])==dist(sx,sy,a[i],b[i]))
        kk++;
    if (kk>ans)
    {
        ans=kk;
        xx=x;
        yy=y;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>sx>>sy;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    ans=-1;
    xx=-1;
    yy=-1;
    up(sx+1,sy);
    up(sx,sy+1);
    up(sx-1,sy);
    up(sx,sy-1);
    cout<<ans<<"\n";
    cout<<xx<<" "<<yy<<"\n";
}