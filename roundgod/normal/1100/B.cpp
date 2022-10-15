#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x,a[MAXN],ans[MAXN];
multiset<int> s;
int main()
{
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) s.insert(0);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        s.erase(s.find(a[x]));
        a[x]++;
        s.insert(a[x]);
        if(*s.begin()>cnt)
        {
            cnt++;
            ans[i]=1;
        }
        else ans[i]=0;
    }
    for(int i=1;i<=m;i++) printf("%d",ans[i]);
    puts("");
    return 0;
}