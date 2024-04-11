#include<bits/stdc++.h>
using namespace std;
string s[100009];
long long nS[100009];
long long nH[100009];
main()
{
   long long n;
   cin >> n;
   long long ans=0;
   vector<pair<double,pair<long long,long long> > >V;
   for (long long i =0; i < n; i++)
   {
       cin >> s[i];
       long long S=0;
       for (long long j = 0; j <s[i].size(); j++)
       {
           if(s[i][j]=='h')
            ans+=S,nH[i]++;
            else nS[i]++,S++;
       }
       if(nS[i]==0) V.push_back({1000000,{nS[i],nH[i]}}); else
       V.push_back({(double)nH[i]/nS[i],{nS[i],nH[i]}});
   }
   sort(V.begin(),V.end());
   long long S=0;
   for (long long i =0; i < V.size(); i++)
   {
       ans+=S*V[i].second.second;
       S+=V[i].second.first;
   }
   cout<<ans<<endl;
}