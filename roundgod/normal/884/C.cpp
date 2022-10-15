#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n,k;
int p[MAXN];
bool used[MAXN];
vector<int> save;
void dfs(int x)
{
    used[x]=true;
    int s=1;
    while(!used[p[x]])
    {
        x=p[x];
        used[x]=true;
        s++;
    }
    save.push_back(s);
}
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        if(!used[i]) dfs(i);
    int k=save.size();
    sort(save.begin(),save.end());
    if(k==1) {printf("%I64d\n",(ll)save[0]*save[0]); return 0;}
    else
    {
        save[k-2]+=save[k-1];
        ll ans=0;
        for(int i=0;i<k-1;i++)
            ans+=(ll)save[i]*save[i];
        printf("%I64d\n",ans);
    }
    return 0;
}