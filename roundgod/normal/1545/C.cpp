#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int a[2*MAXN][MAXN];
bool same[2*MAXN][2*MAXN];
bool used[2*MAXN];
vector<int> pos[MAXN];
int cnt[MAXN][MAXN];
vector<int> ans;
void del(int x)
{
    //printf("deleted %d\n",x);
    used[x]=true;
    for(int i=1;i<=n;i++) cnt[i][a[x][i]]--;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=n;j++) 
            {
                scanf("%d",&a[i][j]);
                cnt[j][a[i][j]]++;
            }
        for(int i=1;i<=2*n;i++)
            for(int j=i+1;j<=2*n;j++)
            {
                same[i][j]=same[j][i]=false;
                for(int k=1;k<=n;k++) if(a[i][k]==a[j][k]) {same[i][j]=same[j][i]=true; break;}
            }
        memset(used,false,sizeof(used));
        int res=1;
        while(ans.size()<n)
        {
           // puts("here");
            //look for a one
            P p=P(-1,-1);
            for(int i=1;i<=n;i++)
            {
                if(p.F!=-1) break;
                for(int j=1;j<=n;j++)
                    if(cnt[i][j]==1)
                    {
                        p=P(i,j);
                        break;
                    }
            }
            if(p.F==-1)
            {
                res=2LL*res%MOD;
                int id=-1;
                for(int i=1;i<=2*n;i++) if(!used[i]) {id=i; break;}
                ans.push_back(id);
                del(id);
                for(int i=1;i<=2*n;i++) if(!used[i]&&i!=id&&same[i][id]) del(i);
            }
            else
            {
                int id=-1;
                for(int i=1;i<=2*n;i++) if(!used[i]&&a[i][p.F]==p.S) {id=i; break;}
                ans.push_back(id);
                del(id);
                for(int i=1;i<=2*n;i++) if(!used[i]&&i!=id&&same[i][id]) del(i);
            }
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",res);
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}