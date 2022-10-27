#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
typedef __int64 ll;
int par[100000+10],num[100000+10],cnt[100000+10],used[100000+10];
int n,m,res=0;
vector<int> vec[100000+10];
void dfs(int node,int rank,int cnt)
{
    if(used[node]) return;
    used[node]=1;
    int k=0;
    for(int i=0;i<vec[node].size();i++)
    {
        int tmp=vec[node][i];
        if(!used[tmp]){
            k++;
            if(num[tmp]==1){
                dfs(tmp,rank+1,max(rank+1,cnt));
            }else{
                dfs(tmp,0,cnt);
            }
        }
    }

    if(k==0){
        if(cnt<=m)
        {
            res++;
        }
        return;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    memset(used,0,sizeof(used));
    for(int i=1;i<=n-1;i++)
    {
        int a,b;cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    if(num[1]) dfs(1,1,1);
    else dfs(1,0,0);
    cout<<res<<endl;
}