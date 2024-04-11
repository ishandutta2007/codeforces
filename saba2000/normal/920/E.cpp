#include<bits/stdc++.h>
using namespace std;
int cnt,f[200009];
set<int > S;
vector<int> v[200009];
void dfs(int x)
{
    if(S.find(x)!=S.end())S.erase(S.find(x));
    f[x]=1;
    cnt++;
    vector<int > V,V1;
    for (int i =0 ; i <v[x].size(); i++)
    {
        if(S.find(v[x][i])!=S.end())
        S.erase(S.find(v[x][i])),V.push_back(v[x][i]);
    }
    for (auto it=S.begin(); it!=S.end(); it++)
    {
        V1.push_back(*it);
    }
    for (int i=0; i<V.size(); i++)
    S.insert(V[i]);
    for (int i=0; i<V1.size(); i++)
    S.erase(S.find(V1[i]));
    for (int i=0; i<V1.size(); i++)
    dfs(V1[i]);
}
main()
{
    int n,m;
    cin >>n >>m;
    for (int i=1; i<=n; i++)
     S.insert(i);
    for (int i=0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> ans;
   for (int i=1; i<=n; i++)
   {
       if(f[i]==0) {cnt=0;dfs(i); ans.push_back(cnt);}
   }
   sort(ans.begin(),ans.end());
   cout<<ans.size()<<endl;
   for (int i=0; i<ans.size(); i++)
   printf("%d ",ans[i]);
   cout<<endl;
}