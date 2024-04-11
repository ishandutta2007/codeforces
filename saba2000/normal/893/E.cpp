#include<bits/stdc++.h>
using namespace std;
int K=1000000;
int p[1000009];
int c[2000009][21];
long long P[1000009];
long long mod=1000000007;
main()
{
    P[0]=1;
    for (int i=1; i<=K; i++)
    P[i]=P[i-1]*2%mod;
   for (int i=2; i<=K; i++)
   {
      if(p[i]==0)
      {
          for (int j=i; j<=K; j+=i)
          p[j]=i;
      }
   }
   for (int i=0; i<=2*K; i++)
   {
       if(i<=20) c[0][i]=0;
       c[i][0]=1;
       
   }
   for (int i=1; i<=2*K; i++)
   for (int j=1; j<=20; j++)
       c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
   int q;
   cin>>q;
   while(q--)
   {
       int x,y;
       cin>>x>>y;
       vector<pair<int,int> > v;
       while(x>1)
       {
           if(v.size()) if (v[v.size()-1].first==p[x])
           v[v.size()-1].second++;
           else
           v.push_back({p[x],1});
           else
           v.push_back({p[x],1});
           x/=p[x];
       }
       long long ans=1;
       for (int i=0; i<v.size(); i++)
       ans=(ans*(long long)c[v[i].second+y-1][v[i].second])%mod;    
   
       cout<<ans*P[y-1]%mod<<endl;
   }
   
}