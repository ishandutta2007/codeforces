#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
char str[MAXN][MAXN];
int x,y;
int cntO[3],cntX[3];
void solve(int x,int y)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if((i+j)%3==x&&str[i][j]=='O') str[i][j]='X';
            if((i+j)%3==y&&str[i][j]=='X') str[i][j]='O';
        }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        memset(cntO,0,sizeof(cntO)); memset(cntX,0,sizeof(cntX));
        int k=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(str[i][j]=='O') cntO[(i+j)%3]++,k++;
                if(str[i][j]=='X') cntX[(i+j)%3]++,k++;
            }
        bool f=false;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==j) continue;
                if((cntO[i]+cntX[j])*3<=k) {f=true; solve(i,j); break;}
            }
            if(f) break;
        }
        assert(f);
        for(int i=0;i<n;i++) printf("%s\n",str[i]);
    }
    return 0;
}