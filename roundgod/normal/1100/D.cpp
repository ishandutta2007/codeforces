#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y,k,xx,yy;
bool rook[MAXN][MAXN];
P rk[MAXN];
void mov(int dx,int dy)
{
    if(dx!=0&&dy!=0&&rook[x+dx][y+dy])
    {
        assert(!rook[x][y+dy]);
        printf("%d %d\n",x,y+dy);
        y=y+dy;
        fflush(stdout);
        scanf("%d%d%d",&k,&xx,&yy);
        assert(k==-1);
        exit(0);
    }
    printf("%d %d\n",x+dx,y+dy);
    fflush(stdout);
    x+=dx;y+=dy;
    scanf("%d%d%d",&k,&xx,&yy);
    if(k==-1) exit(0);
    rook[rk[k].F][rk[k].S]=false;
    rook[xx][yy]=true;
    rk[k]=P(xx,yy);
}
int main()
{
    scanf("%d%d",&x,&y);
    for(int i=1;i<=666;i++)
    {
        scanf("%d%d",&xx,&yy);
        rook[xx][yy]=true;
        rk[i]=P(xx,yy);
    }
    while(x<500) mov(1,0);
    while(x>500) mov(-1,0);
    while(y<500) mov(0,1);
    while(y>500) mov(0,-1);
    int cnt0=0,cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=666;i++)
    {
        if(rk[i].F>=500||rk[i].S<=500) cnt0++;
        if(rk[i].F>=500||rk[i].S>=500) cnt1++;
        if(rk[i].F<=500||rk[i].S>=500) cnt2++;
        if(rk[i].F<=500||rk[i].S<=500) cnt3++;
    }
    if(cnt0>=500) while(true) mov(1,-1);
    if(cnt1>=500) while(true) mov(1,1);
    if(cnt2>=500) while(true) mov(-1,1);
    if(cnt3>=500) while(true) mov(-1,-1);
    return 0;
}