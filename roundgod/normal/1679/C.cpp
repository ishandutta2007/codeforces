#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define x1 cjbsb
#define y1 sbcjb
#define x2 dsakd
#define y2 daski
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int bit[2][MAXN];
int cnt[2][MAXN];
int sum(int id,int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,int x)
{
    while(i<=n)
    {
        bit[id][i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    memset(bit,0,sizeof(bit));
    memset(cnt,0,sizeof(cnt));
    while(q--)
    {
        int t,x1,y1,x2,y2;
        scanf("%d%d%d",&t,&x1,&y1);
        if(t==3)
        {
            scanf("%d%d",&x2,&y2);
            if(sum(0,x2)-sum(0,x1-1)==x2-x1+1||sum(1,y2)-sum(1,y1-1)==y2-y1+1) puts("Yes"); else puts("No");
        }
        else 
        {
            if(t==1)
            {
                cnt[0][x1]++; if(cnt[0][x1]==1) add(0,x1,1);
                cnt[1][y1]++; if(cnt[1][y1]==1) add(1,y1,1);
            }
            else
            {
                cnt[0][x1]--; if(cnt[0][x1]==0) add(0,x1,-1);
                cnt[1][y1]--; if(cnt[1][y1]==0) add(1,y1,-1);
            }
        }
    }
    return 0;
}