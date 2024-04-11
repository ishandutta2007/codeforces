#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<pair<long long,long long> > v[1000009];
vector<pair<long long,long long> > o[1000009];
vector<pair<long long,pair<long long,long long> > > z,z1;
long long M[1000009],M1[1000009];
long long C[1000009],C1[1000009];
main(){
  long long n,m,k;
  cin>>n>>m>>k;
  for (long long i=0; i<m; i++)
  {
      long long d,f,t,c;
      cin>>d>>f>>t>>c;
      if(t==0) {v[f].push_back({d,c}); z.push_back({d,{c,f}});}
      else {o[t].push_back({d,c}); z1.push_back({d,{c,t}});}
  }
  long long Ff=0,F1=1000000000;
 for (long long i=1; i<=n; i++)
 {
     long long f=i;
     if(v[f].size()==0 || o[f].size()==0) {cout<<-1<<endl; return 0;}
     sort(v[f].begin(),v[f].end());
     Ff=max(Ff,v[f][0].first);
     sort(o[f].rbegin(),o[f].rend());
     F1=min(F1,o[f][0].first);
 }
 sort(z.begin(),z.end());
 sort(z1.begin(),z1.end());
long long i=0, KK=0;
 while(z[i].first<=Ff && i<z.size()) {
 if(C[z[i].S.S]==0) {C[z[i].S.S]=z[i].S.F; KK+=z[i].S.F;}
 else if(z[i].S.F<C[z[i].S.S])
    {KK-=C[z[i].S.S];
 C[z[i].S.S]=z[i].S.F;
 KK+=z[i].S.F;}
 i++;
}
for (long long j=0; j<Ff; j++)
    M[j]=1e18;
    M[Ff]=KK;
for (i; i<z.size(); i++)
{
   if(C[z[i].S.S]==0) {C[z[i].S.S]=z[i].S.F; KK+=z[i].S.F;}
 else if(z[i].S.F<C[z[i].S.S]) {KK-=C[z[i].S.S]; C[z[i].S.S]=z[i].S.F;
 KK+=z[i].S.F;}
 //cout<<KK<<endl;
 M[z[i].F]=KK;

}
for (long long i=1; i<=1000000; i++)
   {

    if(M[i]==0) M[i]=M[i-1];
    else M[i]=min(M[i],M[i-1]);
   // cout<<i<<" "<<M[i]<<endl;
    }
reverse(z1.begin(),z1.end());

  i=0,KK=0;
  //cout<<z1[0].first<<" "<<F1<<endl;
 while(z1[i].first>=F1 && i<z1.size()) {
 if(C1[z1[i].S.S]==0) {C1[z1[i].S.S]=z1[i].S.F; KK+=z1[i].S.F;}
 else if(z1[i].S.F<C1[z1[i].S.S]) {KK-=C1[z1[i].S.S]; C1[z1[i].S.S]=z1[i].S.F;
 KK+=z1[i].S.F;}
 //cout<<KK<<endl;
 i++;
}

for (long long j=1000000; j>F1; j--)
    M1[j]=1e18;
    M1[F1]=KK;
for (i; i<z1.size(); i++)
{
   if(C1[z1[i].S.S]==0 ) {C1[z1[i].S.S]=z1[i].S.F; KK+=z1[i].S.F;}
 else if(z1[i].S.F<C1[z1[i].S.S]) {KK-=C1[z1[i].S.S]; C1[z1[i].S.S]=z1[i].S.F;
 KK+=z1[i].S.F;}
 M1[z1[i].F]=KK;
  //cout<<" "<<KK<<endl;

}

for (long long i=999999; i>=0; i--)
   {

       if(M1[i]==0) M1[i]=M1[i+1]; else
    M1[i]=min(M1[i],M1[i+1]);}
long long ans=1e18;
for (long long i=0; i<=1000000-k-1; i++)
    {ans=min(ans,M[i]+M1[i+k+1]);
  //  cout<<ans<<endl;
 // cout<<M[i]<<" "<<M1[i+k+1]<<endl;
    }
//1 2 3 4
if(ans>1e17) cout<<-1<<endl; else
cout<<ans<<endl;
}