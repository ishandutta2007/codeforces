#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int p[MAXN];
int ask(int pos)
{
    printf("? %d\n",pos);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void answer()
{
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",p[i]);
    puts("");
    fflush(stdout);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) p[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(!p[i])
            {
                vector<int> v;
                int now=ask(i); v.push_back(now);
                do
                {
                    now=ask(i);
                    if(now==v[0]) break; else v.push_back(now);
                }while(true);
                for(int i=0;i<(int)v.size();i++) p[v[i]]=v[(i+1)%(int)v.size()];
            }
        }
        answer();
    }
    return 0;
}