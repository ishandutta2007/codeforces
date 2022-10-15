#include<bits/stdc++.h>
#define MAXN 305
using namespace std;
map <string, int> mymap;
string save[2*MAXN];
int G[2*MAXN][2*MAXN];
int n,a,b,k,f,p;
vector<int> ans;
int main()
{
    scanf("%d %d %d %d %d",&n,&a,&b,&k,&f);
    memset(G,0,sizeof(G));
    int id=1;
    for(int i=0;i<n;i++)
    {
        cin>>save[2*i];
        int fee;
        map <string, int>::iterator it= mymap.find(save[2*i]);
        if(it==mymap.end())
        {
            mymap[save[2*i]]=id;
            id++;
        }
        if(2*i>0&&save[2*i]==save[2*i-1]) fee=b; else fee=a;
        cin>>save[2*i+1];
        it= mymap.find(save[2*i+1]);
        if(it==mymap.end())
        {
            mymap[save[2*i+1]]=id;
            id++;
        }
        int x=mymap[save[2*i]],y=mymap[save[2*i+1]];
        G[x][y]+=fee;
        G[y][x]+=fee;
    }
    for(int i=1;i<=id;i++)
        for(int j=i+1;j<=id;j++)
          if(G[i][j]>0) ans.push_back(G[i][j]);
    sort(ans.begin(),ans.end());
    int res=0;
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(ans[i]>f&&k>0)
        {
            res+=f;
            k--;
        }
        else res+=ans[i];
    }
    printf("%d\n",res);
    return 0;
}