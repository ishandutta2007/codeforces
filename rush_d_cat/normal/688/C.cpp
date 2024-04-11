#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int par[200000+10],rank[200000+10],used[200000+10];
vector<int> res1,res2;
void init(int n)
{
    for(int i=1;i<=n;i++) par[i]=i,rank[i]=0;
}

int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) par[x]=y;
    else{
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int m,n;cin>>m>>n;
    init(2*m);
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        used[a]=used[b]=1;
        unite(a,b+m);unite(a+m,b);
    }
    int tmp=1;while(!used[tmp]) tmp++;
    bool flag=1;
    for(int i=tmp;i<=m;i++)
    {
        if(!used[i]) continue;
        if(same(i,tmp)&&same(i,tmp+m)) flag=0;
        else if(!same(i,tmp)&&!same(i,tmp+m)){
            res2.push_back(i);
            unite(i,tmp+m);
            unite(i+m,tmp);
        }
        else if(same(i,tmp)) res1.push_back(i);
        else if(same(i,tmp+m)) res2.push_back(i);
    }
    if(!flag){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",res1.size());
    for(int i=0;i<res1.size();i++){
        printf("%d",res1[i]);
        if(i==res1.size()-1) printf("\n");
        else printf(" ");
    }
    printf("%d\n",res2.size());
    for(int i=0;i<res2.size();i++){
        printf("%d",res2[i]);
        if(i==res2.size()-1) printf("\n");
        else printf(" ");
    }
}