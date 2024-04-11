#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
string str[MAXN];
int cnt[2][2];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) 
        {
            cin>>str[i];
            for(int j=0;j<m;j++)
            {
                int id=(i+j)&1;
                if(str[i][j]=='R') cnt[id][0]++;
                if(str[i][j]=='W') cnt[id][1]++;
            }
        }
        if(!cnt[0][0]&&!cnt[1][1])
        {
            puts("YES");
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) if((i+j)&1) printf("R"); else printf("W");
                puts("");
            }
        }
        else if(!cnt[1][0]&&!cnt[0][1])
        {
            puts("YES");
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) if((i+j)&1) printf("W"); else printf("R");
                puts("");
            }
        }
        else puts("NO");
    }
    return 0;
}