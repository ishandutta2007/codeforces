#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,r,c,k;
char str[MAXN][MAXN];
char get_ch(int id)
{
    if(id<26) return 'a'+id;
    else if(id<52) return 'A'+id-26;
    else return '0'+id-52;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&r,&c,&k);
        int cnt=0;
        for(int i=1;i<=r;i++)
        {
            scanf("%s",str[i]+1);
            for(int j=1;j<=c;j++) if(str[i][j]=='R') cnt++;
        }
        int ave=cnt/k,rem=cnt%k;
        int x=1,y=1;
        for(int i=0;i<k;i++)
        {
            int need=ave+(i<rem?1:0);
            do
            {
                if(str[x][y]=='R')
                {
                    if(!need) break;
                    else need--;
                }
                str[x][y]=get_ch(i);
                if(x&1) y++; else y--;
                if(y==0) {x++; y=1;}
                else if(y==c+1) {x++; y=c;}
            }while(x<=r);
        }
        for(int i=1;i<=r;i++) printf("%s\n",str[i]+1);
    }
    return 0;
}