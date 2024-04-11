#include <iostream>
#include <bits/stdc++.h>
#define MAX 200000+1
using namespace std;
vector <long long> v[MAX];
vector <long long> vv;
map<long long,bool>mp;
bool vis[MAX]={false};
int sum;
long long me[MAX],father;
void dfs(long long x,long long father){
   int c=0;
    for (long long  i=0;i<v[x].size();i++){
        if (vis[v[x][i]]==false)
        {
            c++;
            if (c==me[x]||c==me[father])
        while (c==me[x] || c==me[father]){
            c++;
        }
       // cout<<"   c= "<<c<<" x= "<<x<<" father= "<<father<<"   v[x][i]= "<<v[x][i]<<" "<<endl;
        vis[v[x][i]]=true;
        vv.push_back(c);
        me[v[x][i]]=c;
        dfs(v[x][i],x);}
    }
}
int main()
{
    long long n;
    cin>>n;
    me[1]=1;
    me[0]=0;
    for (int i=0;i<n-1;i++){
        long long u,e;
        cin>>u>>e;
        v[u].push_back(e);
        v[e].push_back(u);
    }
    vv.push_back(1);
    vis[1]=true;
    dfs(1,0);
    for (int i=0;i<vv.size();i++){
        if (mp[vv[i]]==false)
            sum++;
        mp[ vv[i] ]=true;
    }
    cout<<sum<<endl;
    for (int i=1;i<=n;i++){
        cout<<me[i]<<" ";

    }
    return 0;
}