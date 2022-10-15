#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int len[MAXN];
int state[MAXN];
int query()
{
    string str="";
    for(int i=1;i<=m;i++) if(state[i]) str+='1'; else str+='0';
    cout<<"? "<<str<<endl;
    cout.flush();
    int x;
    scanf("%d",&x);
    return x;
}
void answer(ll ans)
{
    printf("! %lld\n",ans);
    fflush(stdout);
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(state,0,sizeof(state));
    vector<P> v;
    for(int i=1;i<=m;i++)
    {
        state[i]=1;
        len[i]=query();
        v.push_back(P(len[i],i));
        state[i]=0;
    }
    sort(v.begin(),v.end());
    ll ans=0,last=0;
    for(int i=0;i<m;i++)
    {
        state[v[i].S]=1;
        ll res=query();
        if(res==last+len[v[i].S]) ans+=len[v[i].S];
        last=res;
    }
    answer(ans);
    return 0;
}