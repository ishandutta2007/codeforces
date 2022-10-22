#include<bits/stdc++.h>
#define int long long
using namespace std;
struct UnionFind{
  vector<int>par;
  UnionFind(int n):par(n,-1){}
  int find(int x){return par[x]<0?x:par[x]=find(par[x]);}
  int size(int x){return -par[find(x)];}
  void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(par[x]>par[y])swap(x,y);
    par[x]+=par[y],par[y]=x;
  }
};
signed main(){
  int t;cin>>t;
  while(t--){
    int n;string s;cin>>n>>s;
    UnionFind UF(n);
    for(int i=0;i<n-1;i++)if(s[i]!=s[i+1])UF.unite(i,i+1);
    for(int i=0;i<n+1;i++){
      int ans=0;
      if(i!=0&&s[i-1]=='L')ans=max(ans,UF.size(i-1));
      if(i!=n&&s[i]=='R')ans=max(ans,UF.size(i));
      cout<<ans+1<<(i==n?'\n':' ');
    }
  }
}