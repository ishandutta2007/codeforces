#include<bits/stdc++.h>
using namespace std;
long long S[399];
long long a[100009];
long long ad[329];
long long ss[100009];
int tt[320][100009];
long long ba[329];
bool c[320][100009];
int n,m,q;
vector<int> v[100009];
vector<int> b;
int z[100009];
int f[100009];
int main()
{cin>>n>>m>>q;
for(int i=1; i<=n; i++)
cin>>a[i];
for(int i=1; i<=m; i++)
{int s;long long r=0;
cin>>s;
ss[i]=s;
if(s>=300) {b.push_back(i); z[i]=b.size()-1;}
else f[i]=1;
for(int j=0; j<s; j++)
{int p;
cin>>p;
v[i].push_back(p);
if(!f[i]) c[b.size()-1][p]=1;r+=a[p];}
if(!f[i]) S[b.size()-1]=r;
}
for (int i=0; i<b.size(); i++)
{for (int j=0; j<n; j++)
{for(int k=0; k<v[j].size(); k++)
if(c[i][v[j][k]])tt[i][j]++;
}}
for(int i=0; i<q; i++)
{char c;
cin>>c;
if(c=='+'){int l,r; cin>>l>>r;
if(f[l]==0){ba[z[l]]+=r;}
else {for(int i=0; i<v[l].size(); i++) a[v[l][i]]+=r;
for(int i=0; i<b.size(); i++)
ad[i]+=(long long)tt[i][l]*r;
}}
else{
int l;
cin>>l;
if(f[l]==1){long long r=0;for(int i=0; i<v[l].size(); i++) r+=a[v[l][i]];
for(int i=0; i<b.size(); i++)
r+=tt[i][l]*ba[i];
cout<<r<<endl;}
else{long long r=ad[z[l]]+S[z[l]];
for(int i=0; i<b.size(); i++)
r+=(long long)tt[i][l]*ba[i];
cout<<r<<endl;}}}}