#include<bits/stdc++.h>
using namespace std;
int e[200009];
vector<int> v[200009];
int f[200009],F[200009];
main()
{
   int n,m;
   cin>>n>>m;
   for (int i=0; i<n; i++)
   {
       cin>>e[i];
   }
   for (int i=0; i<m; i++)
   {
       int a,b;
       cin>>a>>b;
       v[b].push_back(a);
       F[a]++;
   }
   queue<int> q[2];
   for (int i=0; i<n; i++)
    if(F[i]==0)
    {q[e[i]].push(i);}
    int ans=0;
   while(q[0].size()+q[1].size())
   {
       int x=0;
       if(q[0].size()==0)
       {
           ans++;
           while(q[1].size())
           {

           x=q[1].front();
           q[1].pop();
           for (int i=0; i<v[x].size(); i++)
           {
               if(F[v[x][i]]==1)
               {
                   q[e[v[x][i]]].push(v[x][i]);
                   F[v[x][i]]=0;
               }
               else F[v[x][i]]--;
           }
           }
           continue;
       }
       x=q[0].front();
       q[0].pop();
      for (int i=0; i<v[x].size(); i++)
           {
               if(F[v[x][i]]==1)
               {
                   q[e[v[x][i]]].push(v[x][i]);
                   F[v[x][i]]=0;
               }
               else F[v[x][i]]--;
           }

   }
    cout<<ans<<endl;
}