#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d[MAXN];
set<P> edges;
vector<int> even,odd;
void ask(int id)
{
    printf("? %d\n",id);
    fflush(stdout);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    for(int i=1;i<=n;i++) if(d[i]==1) edges.insert(P(min(id,i),max(id,i)));
}
void answer()
{
    assert((int)edges.size()==n-1);
    printf("!\n"); 
    for(auto p:edges) printf("%d %d\n",p.F,p.S);
    fflush(stdout);
}
int main()
{
    scanf("%d",&n);
    ask(1);
    for(int i=2;i<=n;i++)
    {
        if(d[i]&1) odd.push_back(i); else even.push_back(i);
    }
    if((int)odd.size()<=(int)even.size()) for(auto x:odd) ask(x);
    else for(auto x:even) ask(x);
    answer();
    return 0;
}