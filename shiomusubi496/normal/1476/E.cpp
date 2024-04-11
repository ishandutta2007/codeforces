#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>G[1<<20];
map<string,int>mp;
bool seen[1<<20],vst[1<<20];
vector<int>tps;
void dfs1(int v){
  if(vst[v]){
    puts("NO");
    exit(0);
  }
  if(seen[v])return;
  seen[v]=vst[v]=1;
  for(int t:G[v])dfs1(t);
  vst[v]=0;
  tps.push_back(v);
}
signed main(){
  int n,m,k;cin>>n>>m>>k;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    mp[s]=i;
  }
  for(int i=0;i<m;i++){
    bool ok=1;
    string s;int a;cin>>s>>a;--a;
    for(int j=0;j<(1<<k);j++){
      string t=s;
      for(int l=0;l<k;l++)if((j>>l)&1)t[l]='_';
      if(mp.count(t)){
        if(mp[t]==a)ok=0;
        else G[mp[t]].push_back(a);
      }
    }
    if(ok){
      puts("NO");
      return 0;
    }
  }
  fill(seen,seen+n,0);
  fill(vst,vst+n,0);
  for(int i=0;i<n;i++)dfs1(i);
  puts("YES");
  for(int i=0;i<n;i++)cout<<tps[i]+1<<(i==n-1?'\n':' ');
}